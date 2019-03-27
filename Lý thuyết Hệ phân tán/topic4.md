# Tiến trình và luồng

## Từ khoá
* Tiến trình (Process): 1 chương trình đang được chạy trên bộ xử lý ảo của OS
* Luồng (Thread): chạy trên đoạn mã riêng, độc lập với các luồng khác, không trong suốt
* Bảng tiến trình: (Ctrl Alt Del)
* Dispatcher: chia việc cho vy xử lý

## Tiến trình và luồng
### Giới thiệu
* Tiến trình
  * chương trình đang chạy
  * trên bộ xử lý ảo -> cần có bảng tiến trình để kiểm soát thông tin (ram, )
  * đảm bảo trong suốt, độc lập với các tiến trình khác
  * thực hiện swap trên cpu hoặc ổ cứng (nếu process >>)
  * cần có sự hỗ trợ của phần cứng

-> Bảo đảm độ an toàn, độc lập
-> VD: quản lý màn hình, login

Tiến trình chạy -> 1..n luồng
* Luồng
  * có đoạn mã thực thi riêng
  * ngữ cảnh: cpu, bộ đệm, stack
  * chia sẻ cpu, không quá độc lập với nhau
  * hỗ trợ bởi lập trình viên (đa luồng -> mạnh mẽ -> khó code :D)

* Lợi ích đa luồng
  * không bị treo hệ thống
  * ứng dụng tính toán song song: tăng hiệu năng hệ thống (mỗi luồng thuộc một vi xử lý khác nhau)
  * mỗi luồng đảm đương chương trình con -> không cần chuyển ngữ cảnh
  * mô-đun hoá -> mỗi luồng một chức năng
VD: Excel

### Luồng hệ thống tập trung
2 hướng
* user-mode (người dùng)
  * ưu
    * tiết kiệm tài nguyên hệ thống -> tạo/huỷ luồng
    * chuyển ngữ cảnh nhanh
  * nhược
    * lời gọi hệ thống dừng -> kill mọi luồng
* kernel-mode (nhân)
  * ưu
    * không lo killall luồng
  * nhược
    * chi phí lớn
    * chuyển ngữ cảnh tốn kém

-> Light-weigh process (nhẹ)
* Cách hoạt động
  * mỗi tiến trình đơn -> nhiều tiến trình nhẹ
  * sử dụng gói luồng (tạo/huỷ/đồng bộ hoá luồng) ở user -> tiết kiệm chi phí
  * gói luồng: lập lịch cho tiến trình kế tiếp
  * luồng dừng -> lập lịch -> chuyển ngữ cảnh sang luồng mới -> lwp không biết
  * luồng call kill -> chuyển xuống lwp của kernel -> chuyển về user -> không killall

* Ưu điểm
  * thao tác với luồng chi phí thấp
  * kill -> dừng 1 lwp
  * chương trình không nhìn thấy lwp

* Nhược điểm
  * huỷ lwp (vì phải huỷ ở kernel) | không thường xuyên

### Luồng trong hệ phân tán
* Đơn luồng
  * xử lý 1 yêu cầu vào thời điểm
  * tuần tự
  * mỗi tiến trình 1 luồng -> gửi nhiều server
  * nhiều yêu cầu -> xếp vào hàng đợi -> không đảm bảo trong suốt

* Client-server đa luồng
  * nhiều luồng xử lý với mỗi tiến trình client & server
  * cùng lúc xử lý nhiều yêu cầu -> tăng tốc độ/ hiệu năng hệ thống
  * chức năng của server
    * nhận yêu cầu
    * xử lý yêu cầu
    * gửi phản hồi cho client
  * Server có điều phối
    * có Dispatcher điều phối: có yêu cầu -> Dispatcher phân loại -> gửi đến luồng chuyên biệt

_Khác_
* Thread per req
  * sinh luồng cho mỗi yêu cầu mới, tự huỷ sau khi yêu cầu được thực hiện
  * Ưu điểm
    * sinh luồng cho mỗi yêu cầu & tự huỷ -> không cần hàng đợi
    * sinh không giới hạn -> băng thông tối đa
  * Nhược điểm
    * tạo/ huỷ các luồng
    * nhiều yêu cầu -> overheap/luồng cao -> giảm hiệu năng

* Thread per connection
  * sinh luồng cho kết nối mới, tự huỷ sau khi ngắt kết nối
* Thread per object
  * sinh luồng cho đối tượng từ xa (remote) mà mình quản lý, thêm hàng đợi object
-> Ưu điểm: tránh được nhiều luồng
-> Nhược điểm: thêm hàng đợi -> độ trễ cao, cân bằng tải khó
_Hết khác_

* Máy trạng thái
  * 1 luồng nhận request -> đệm còn chỗ? -> thực thi | gửi vào đĩa cứng
  * sẵn sàng xử lý req từ client
  * không cần đa luồng
  * lời gọi xử lý không dừng

* Client đa luồng
  * tách biệt GUI và xử lý -> tăng tốc xử lý & hiệu năng
  * tăng tốc độ làm việc với server khác nhau
  * che giấu chi tiết cài đặt
  VD: browser (duyệt web - tải thẻ html trước khi tải script)

## Ảo hoá
### Vai trò
* Hỗ trợ phần mềm/ thiết lập phần cứng
* Hỗ trợ quản trị các phần mềm

### Kiến trúc
4 kiểu giao diện
  * phần cứng x phần mềm, tập lệnh máy: mọi phần mềm gọi
  * phần cứng x phần mềm, tập lệnh máy: phần mềm có đặc quyền (OS...)
  * lời gọi hệ thống (system calls) cung cấp bởi OS
  * lời gọi thư viện, API

* Máy ảo tiến trình
  * thực hiện trên máy ảo
  * VD: Java

* Kiểm soát
  * che phủ hoàn toàn phần cứng
  * VD: VMWare, Virtual Box

## Di trú mã
Dịch chuyển chương trình giữa các máy, để chương trình chạy ở máy đích

### Lý do
* hiệu năng
VD1: chuyển một phần ứng dụng từ server -> client | điền form
VD2: tính toán song song

* độ mềm dẻo

### Mô hình
Tiến trình: mã, tài nguyên, trạng thái
Di trú mã -> di trú 3 yếu tố của tiến trình

* Weak Mobility
  * di trú mã, và một phần tài nguyên
  * lợi ích: máy đích chạy chương trình đó
  VD: Java Uplet

* Strong Mobility
  * di trú mã, và gửi thêm trạng thái
  * tạm dừng ở máy này -> chuyển sang máy khác

### Tài nguyên cục bộ
* Liên kết tài nguyên - tiến trình
  * định danh: Url...
  * giá trị: bộ thư viện chuẩn (C, Java)
  * kiểu dữ liệu (yếu nhất) tham chiếu thiết bị cục bộ ~ máy in, màn hình...

* Liên kết tài nguyên -  máy tính
  * không gắn kết: tệp liên kết chương trình
  * tương đối: csdl cục bộ & website
  * cục bộ: 1 máy tính trong môi trường cụ thể

### Hệ thống không đồng nhất
Không đồng nhất -> mã không chạy -> dịch lại mã
* thông dịch
* biên dịch
