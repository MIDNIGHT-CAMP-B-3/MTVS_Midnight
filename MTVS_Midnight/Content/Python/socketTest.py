import socket
import struct

# 클라이언트 소켓 설정
udp_ip = "203.0.113.25"  # 서버의 공인 IP 주소
udp_port = 3333  # 서버에서 포트 포워딩한 포트 번호
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # UDP 소켓 생성

print("서버로부터 데이터를 기다리고 있습니다...")

try:
    while True:
        data, addr = sock.recvfrom(1024)  # 서버로부터 데이터 수신
        left_shoulder_x, left_shoulder_y, left_shoulder_z, right_shoulder_x, right_shoulder_y, right_shoulder_z = struct.unpack('ffffff', data)
        
        print(f"Received data from {addr}:")
        print(f"Left Shoulder - X: {left_shoulder_x}, Y: {left_shoulder_y}, Z: {left_shoulder_z}")
        print(f"Right Shoulder - X: {right_shoulder_x}, Y: {right_shoulder_y}, Z: {right_shoulder_z}")
except OSError as e:
    print(f"소켓 오류 발생: {e}")
finally:
    sock.close()