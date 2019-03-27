# Mô hình và kiến trúc

## Cơ bản về kiến trúc & mô hình
* Định nghĩa kiểu kiến trúc:
  - các thành phần (component) : các đơn vị mô-đun có giao diện tuỳ chỉnh theo môi trường
  - kết nối lại với nhau (qua các connector)

* Phân biệt thông qua các thành phần
  - cách thức kết nối
  - cách thức dữ liệu trao đổi
  - cấu hình như thế nào?

* Phân loại
  - phân tầng
  - hướng đối tượng
  - hướng dữ liệu
  - hướng sự kiện

### Phân tầng
Ý tưởng
  * chia nhỏ chức năng lớn -> chức năng nhỏ.
  * tầng trên gọi request xuống tầng dưới, tầng dưới trả response về tầng trên

VD: mô hình OSI

Giao thức:
  * tập hợp các quy tắc/ quy ước để đảm bảo các máy tính trên mạng giao tiếp được với nhau
  * phân loại
    - hướng kết nối: 2 thực thể (entity) phải xây dựng 1 kênh truyền (TCP/IP)
    - hướng không kết nối: không cần kênh truyền (UDP)
    - tin cậy: nhận -> thông báo đã nhận
    - không tin cậy

### Hướng đối tượng
Ý tưởng
  * component: object (đối tượng)
    - objClient
    - objServer
  * connector: method call (lời gọi thủ tục)
    - lỏng -> obj không đồng nhất có khả năng trao đổi thông tin với nhau

VD: CORBA (chuẩn hoá lời gọi thủ tục -> cho phép các chương trình không cùng ngôn ngữ giao tiếp với nhau)

### Hướng sự kiện
Cách hoạt động: point-point hoặc event-bus

VD: truyền Intent trong Android

Liên kết lỏng: component khác nhau về phần cứng + phần mềm

### Hướng dữ liệu
Tiến trình tách rời theo thời gian, không cần phải đang chạy cùng lúc

### Mô hình
Phân loại (`loại: đánh giá`)
  * Lỗi
  * Tương tác
  * Bảo mật

## Kiến trúc hệ thống
### Tập trung
> Client-server
Định nghĩa
  * Client
    - tiến trình (process) yêu cầu dịch vụ từ phía server 
    - chờ và hiển thị kết quả cho người dùng
  * Server: 
    - tiến trình triển khai dịch vụ nhất định
    - lắng nghe yêu cầu, đóng gói và trả kết quả về cho client
  * Tương tác (qua giao thức):
    - hướng kết nối
    - không kết nối

Vấn đề:
  * đăng ký: server cần đăng ký để client biết địa chỉ trỏ tới (ví dụ: dịch vụ DNS)
  * lập lại yêu cầu (Idempotent): mất gói tin?
  * bộ nhớ trạng thái
  * lựa chọn giao thức
    - hướng kết nối: đáng tin cậy, hiệu năng không cao (tốn thời gian tạo & huỷ kênh truyền)
    - hướng không kết nối: nhanh và hiệu quả, không có kênh truyền riêng

> Phân tầng ứng dụng
Lý do: nếu một server muốn nhận dữ liệu từ server khác -> trở thành client -> cần phân tán ứng dụng client-server vào nhiều máy tính khác nhau

Chia làm 3 tầng
  * giao diện người dùng
    - quản lý giao diện với người dùng
    - cung cấp chương trình để người dùng tương tác với hệ thống (w/ or w/o GUI)
  * nghiệp vụ
    - chứa chức năng xử lý chính của ứng dụng
  * dữ liệu
    - lưu trữ dữ liệu cho các ứng dụng sử dụng

> Đa tầng
Phân loại
  * 2 bên: client - server
  * 3 bên: UI - Application server - Database server

### Không tập trung
Phân phối:
  * dọc: chia chức năng theo cách logic và vật lý lên các máy khác nhau
  * ngang: client/server chia theo cách vật lý thành từng phần logic tương đương, nhận phần công việc tương đương -> _cân bằng tài_
  * peer-to-peer
> có cấu trúc
Mạng overlay
  * các node được tạo từ tiến trình, các đường kết nối biểu diễn các kết nối
  * xây dựng dựa trên thủ tục
    - DHT (bảng băm phân tán)
    - tìm kiếm dữ liệu: băm tên file -> getKey
    - lưu dữ liệu: băm tên file -> saveKey

> không cấu trúc
Vẫn dùng mạng overlay

Xây dựng
  * thuật toán ngẫu nhiên
  * tìm kiếm dữ liệu: truy vấn toàn bộ mạng

### Hỗn hợp
> Máy chủ biên (Edge-server system)
Ý tưởng: 
  * dữ liệu (content server) -> server biên -> client
  * cung ứng nội dung cho client, mà không cần phải kết nối trực tiếp tới server

> Hệ phân tán hợp tác (Collaborative distributed system)
BitTorrent
Tải file -> tìm tracker (`.torrent`) chứa thông tin về các node chứa dữ liệu -> tải dữ liệu từ các node còn lại

## Mô hình căn bản
### Tương tác
Vấn đề
  * Hiệu năng -> đặc tính (delay, bandwidth...)
  * Mô hình hệ thống

Kiểu
  * phân tán đồng bộ (với _ràng buộc_)
    - thời gian chạy có ràng buộc trên và dưới biết trước
    - mỗi thông điệp gửi qua một kênh được nhận trong khoảng thời gian biết trước
    - mỗi tiến trình có đồng hộ cục bộ (rate) có ràng buộc biết trước
    -> chọn khoảng ràng buộc?
  * phân tán không đồng bộ (không giới hạn _ràng buộc_)

Ví dụ: trong suốt độ trễ (tải trước nội dung nhẹ như văn bản trước khi tải xong nội dung nặng như video)

### Lỗi
Định nghĩa & phân loại lỗi -> phân tích & xử lý lỗi -> không làm ảnh hưởng tới quá trình chạy hệ thống

Kiểu
  * lỗi bỏ qua

### Bảo mật
Định nghĩa & phân loại kiểu tấn công -> phân tích & xử lý mối đe doạ -> thiết kế hệ thống chống lại các cuộc tấn công

