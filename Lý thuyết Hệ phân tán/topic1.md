# Giới thiệu môn học

## Từ khoá
* Hệ phân tán (DS): tập hợp máy tính kết nối qua hạ tầng truyền thông cung cấp dịch vụ cho người sử dụng một cách thống nhất như **MỘT** máy tính
* Tính toán khắp nơi và di động (Ubiquitous Computing): tập hợp máy tính kết nối qua hạ tầng truyền thông cung cấp dịch vụ cho người sử dụng một cách thống nhất như **KHÔNG CÓ** máy tính
* Đặc tính: 
  * Chia sẻ thông tin
  * Tính trong suốt
  * Tính mở
  * Tính co giãn

-> Chia sẻ tài nguyên: người dùng sử dụng ở khắp nơi
-> Tính sẵn sàng: một máy tính chết -> máy tính khác thay thế (cân bằng tải)

-> Siêu máy tính: 1 máy - n người dùng

## Định nghĩa
* Máy tính độc lập
  - Gồm những máy tính ở vị trí địa lý xa nhau
  - Có cách trao đổi thông tin với nhau
  - Có phần mềm khác nhau

-> Máy tính độc lập kết nối lẫn nhau (bằng hạ tầng truyền thông) cung cấp dịch vụ cho người sử dụng (một cách thống nhất như một máy tính duy nhất)

### Ví dụ
* WWW (dịch vụ web)
  - Cung cấp cho người dùng các vùng được đánh dấu - trang siêu văn bản (HTML)
  - Thông qua trình duyệt, để trình duyệt điều hướng

## Đặc tính
### Chia sẻ tài nguyên
* Cơ chế: qua 1 phần mềm chia sẻ tài nguyên
* Điểm mạnh
  * tiết kiệm chi phí đầu tư (dùng tài nguyên không nằm trên máy tính của mình)
  * tăng tính sẵn sàng (1 máy hỏng -> dùng máy khác trên hệ thống)
* Điểm yếu
  * cài đặt phần mềm chia sẻ tài nguyên (có kết nối mạng -> lỗ hổng bảo mật) => giảm bảo mật của hệ thống
  * nguy cơ lộ thông tin mật

### Tính trong suốt
#### Góc độ trong suốt
1. Truy cập (Access): cách thức truy cập giống nhau trong mọi trường hợp (ví dụ: giao diện Google)
2. Vị trí (Location): che giấu vị trí của tài nguyên
3. Tái định cư: che giấu tài nguyên khi được di chuyển tới vị trí mới
4. Relocation: che giấu tài nguyên trong quá trình sử dụng (ví dụ: điện thoại di động)
5. Sao lưu (Replication): che giấu bản sao thông tin được tạo ra trên máy cục bộ
6. Concurrency: che giấu thông tin chia sẻ giữa các người dùng (ví dụ: ssl/tls ~ https)
7. Lỗi (Failure): che giấu lỗi trong quá trình sử dụng

#### Mức độ
Tuỳ trường hợp để xác định mức trong suốt -> tiết kiệm chi phí

### Tính mở
* Cho phép thay thế/ thêm mới thành phần (với NSX khác nhau)
* Tương tác giữa các thành phần:
  * giao thức (protocol) >> giao diện
  * điều kiện tương tác: cùng cài đặt 1 `giao diện`
    * đầy đủ (nếu không -> cài đặt khác nhau -> không tương tác được với nhau)
    * trung lập (không phụ thuộc vào công nghệ, nền tảng, hạ tầng)

### Tính co giãn
Đáp ứng thay đổi của hạ tầng xung quanh, qua 3 góc độ
* Quy mô: đảm bảo số lượng người sử dụng
* Địa lý: trên mạng lớn (WAN)
* Tổ chức: tăng tổ chức, thay đổi tổ chức -> phân thành các domain, phân độ tin cậy giữa các domain

-> Thiết kế peer to peer 

