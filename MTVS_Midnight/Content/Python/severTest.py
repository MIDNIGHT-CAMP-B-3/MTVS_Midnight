import cv2
import mediapipe as mp
import socket
import struct
import unreal

# TCP 클라이언트 설정: 서버의 IP 주소와 포트를 설정하고 소켓 객체를 생성합니다.
tcp_ip = "192.168.1.87"  # 서버가 실행 중인 컴퓨터의 IP 주소
tcp_port = 3333  # 서버에서 대기 중인 포트 번호
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # TCP 소켓 생성
sock.connect((tcp_ip, tcp_port))  # 서버에 연결 시도

# MediaPipe 모듈 설정: 포즈 인식 및 랜드마크 그리기를 위한 모듈을 정의합니다.
mp_drawing = mp.solutions.drawing_utils  # 랜드마크와 연결선을 그리는 유틸리티
mp_drawing_styles = mp.solutions.drawing_styles  # 랜드마크 스타일을 지정하는 유틸리티
mp_pose = mp.solutions.pose  # 포즈 인식을 위한 모듈

# 웹캠으로부터 비디오 캡처를 시작합니다.
cap = cv2.VideoCapture(0)  # 기본 웹캠을 사용하여 비디오 캡처 객체 생성

# MediaPipe Pose 모듈을 사용하여 포즈 인식을 수행합니다.
with mp_pose.Pose(
        min_detection_confidence=0.5,  # 최소 검출 신뢰도 설정
        min_tracking_confidence=0.5) as pose:  # 최소 추적 신뢰도 설정
    
    while cap.isOpened():  # 비디오 캡처가 열려 있는 동안 루프를 실행
        success, image = cap.read()  # 웹캠에서 프레임을 읽어옵니다.
        if not success:  # 프레임을 읽어오지 못한 경우
            print("카메라를 찾을 수 없습니다.")  # 에러 메시지 출력
            break  # 루프 종료

        # 이미지를 처리하기 위해 쓰기 가능성을 비활성화하고, RGB로 변환합니다.
        image.flags.writeable = False  # 성능 최적화를 위해 이미지의 쓰기 가능성 비활성화
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # BGR에서 RGB로 색상 공간 변환
        results = pose.process(image)  # 포즈 인식을 수행하여 결과를 얻습니다.

        if results.pose_landmarks:  # 포즈 랜드마크가 감지된 경우
            landmarks = results.pose_landmarks.landmark  # 랜드마크 리스트를 가져옵니다.
            left_shoulder = landmarks[mp_pose.PoseLandmark.LEFT_SHOULDER.value]  # 왼쪽 어깨의 랜드마크 좌표
            right_shoulder = landmarks[mp_pose.PoseLandmark.RIGHT_SHOULDER.value]  # 오른쪽 어깨의 랜드마크 좌표

            # 좌표 데이터를 float 형식으로 구조체에 패킹하여 TCP로 전송합니다.
            data = struct.pack('ffffff', 
                               left_shoulder.x, left_shoulder.y, left_shoulder.z,
                               right_shoulder.x, right_shoulder.y, right_shoulder.z)
            sock.sendall(data)  # 패킹된 데이터를 소켓을 통해 전송

            # 어깨 좌표를 비교하여 해당 결과를 화면에 표시합니다.
            if left_shoulder.x >= right_shoulder.x:  # 왼쪽 어깨가 오른쪽 어깨보다 오른쪽에 있으면
                cv2.putText(image, f"{1}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)
            else:  # 그렇지 않으면
                cv2.putText(image, f"{0}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA)

        # 이미지를 BGR로 변환하고 랜드마크와 연결선을 그립니다.
        image.flags.writeable = True  # 이미지의 쓰기 가능성 다시 활성화
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)  # RGB에서 다시 BGR로 변환
        mp_drawing.draw_landmarks(
            image,  # 이미지를 대상으로
            results.pose_landmarks,  # 포즈 랜드마크를 그립니다.
            mp_pose.POSE_CONNECTIONS,  # 랜드마크 간의 연결선을 그립니다.
            landmark_drawing_spec=mp_drawing_styles.get_default_pose_landmarks_style())  # 기본 스타일 사용

        # 결과 이미지를 화면에 출력합니다.
        cv2.imshow('MediaPipe Pose', image)  # 결과 이미지를 윈도우에 표시
        if cv2.waitKey(1) & 0xFF == 27:  # ESC 키가 눌리면 루프 종료
            break

# 비디오 캡처와 소켓을 닫고 모든 OpenCV 창을 닫습니다.
cap.release()  # 비디오 캡처 해제
sock.close()  # 소켓 닫기
cv2.destroyAllWindows()  # 모든 OpenCV 창 닫기
