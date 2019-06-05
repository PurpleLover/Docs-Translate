# Sao lưu và thống nhất dữ liệu

## 1. Mở đầu

### 1.1 Lý do sao lưu

Các lý do chính
* Độ tin cậy: tăng tính sẵn sàng của hệ thống (nếu có bản sao bị treo -> chuyển sang bản sao khác)
* Hiệu năng: người dùng có thể lựa chọn các bản sao gần nhất (theo vị trí địa lý) để yêu cầu dịch vụ -> chi phí kết nối của hệ thống rẻ nhất có thể
* Khả năng co giãn: hệ thống có thể phân tải cho các bản sao để tăng khả năng phục vụ cho hệ thống. Tuy nhiên, khó đánh giá khả năng co giãn do việc phân tải cho các bản sao đòi hỏi mất thời gian và đầu tư cho thuật toán để thực hiện việc đó

Ví dụ: sao lưu server, sao lưu giữa các client... Yêu cầu đặt ra là dữ liệu phải giống nhau giữa các bản sao, từ đó ta có yêu cầu về tính thống nhất đối với các bản sao trong hệ thống

### 1.2 Tính thống nhất

Yêu cầu là các bản sao cần có một dữ liệu. Tuy nhiên, vấn đề đặt ra là hệ thống không thể cùng lúc đồng bộ hoá dữ liệu giữa các bản sao -> Làm như thế nào? Khi nào? Ta có hai loại tính thống nhất:
- Tính thống nhất yếu (lỏng): không yêu cầu dữ liệu phải thống nhất với nhau ở tất cả các bản sao sau khi cập nhật
- Tính thống nhất mạnh (chặt): có yêu cầu điều đó. Tuy nhiên để đạt được thì phải đánh đổi yêu cầu hiệu năng

Ví dụ: sử dụng bộ nhớ đệm của trình duyệt web. Để đảm bảo tính thống nhất, có 2 cách
- Cấm không cho dùng bộ nhớ đệm: không hay
- Server cập nhật bộ nhớ đệm khi có nội dung thay đổi -> chọn mô hình thống nhất hợp lý

Ưu và nhược điểm của sao lưu
* Ưu
  - cải thiện hiệu năng về thời gian
  - đảm bảo tính co giãn của hệ thống
  - giảm băng thông sử dụng
* Nhược
  - đảm báo tính thống nhất chặt dẫn đến tốn băng thông
  - tuỳ thuộc vào yêu cầu của người dùng

## 2. Mô hình thống nhất hướng dữ liệu

### 2.1 Kho dữ liệu
#### Khái niệm
* là mô hình bộ nhớ chia sẻ dùng chung bao gồm các thao tác đọc, ghi, phân vùng bộ
* các tiến trình có các bản sao cục bộ của kho dữ liệu: là tập hợp các bản sao cục bộ tạo thành kho dữ liệu
* các thao tác trên kho dữ liệu bao gồm:
  - đọc dữ liệu: không làm thay đổi dữ liệu
  - ghi dữ liệu: có thay đổi dữ liệu
* mô hình thống nhất: đặc tả khả năng đáp ứng của kho dữ liệu phân tán về tính thống nhất, bao gồm thoả thuận ràng buộc giữa tiến trình và kho dữ liệu. Ở đây, tiến trình sử dụng dữ liệu trong kho dữ liệu, kho dữ liệu đảm bảo cung cấp dữ liệu một cách thống nhất theo mô hình thống nhất. Ví dụ: khi tiến trình đọc dữ liệu, dữ liệu trả về luôn luôn là của thao tác ghi cuối cùng (-> thao tác ghi nào là cuối cùng?). Cần phải giới hạn các giá trị trả về, nếu giới hạn nhiều thì dễ thực hiện hơn, giới hạn ít thì khó thực hiện hơn.

#### Yêu cầu của mô hình thống nhất
Mức độ thống nhất mà kho dữ liệu yêu cầu khi tiến trình đọc, dữ liệu trả về luôn luôn là dữ liệu của thao tác ghi cuối cùng. Vậy thao tác ghi cuối cùng là thế nào? 

Nếu mức độ lỏng
- thì xử lý cục bộ
- ràng buộc thao tác nhiều và dễ thực hiện

Nếu mức độ chặt
- thì xử lý toàn cục
- ràng buộc thao tác ít và khó thực hiện

Ngoài ra yêu cầu còn liên quan đến thoả thuận mà kho dữ liệu cung cấp cho tiến trình. 

### 2.2 Mô hình thống nhất liên tục
Dựa trên giá trị dữ liệu và các thông số trên bản ghi cục bộ để xác định mức độ thống nhất, các giá trị này có thể là:
* giá trị của dữ liệu
* độ lệch trung bình không vượt quá giá trị thoả thuận
  - chênh lệch thời gian cập nhật của các bản sao cục bộ không vượt quá giá trị thoả thuận
  - chênh lệch sai khác giữa các thứ tự thực hiện trên các bản sao khác nhau không vượt quá giá trị thoả thuận

Khi độ lệch vượt quá giá trị cho trước thì middleware sẽ cập nhật các giá trị cho phù hợp. 
- Với giá trị sai khác thì sẽ cập nhật giá trị cho trước. 
- Với thời gian cập nhật sai khác quá lớn, thì cập nhật lại giá trị mới. 
- Nếu thứ tự thực hiện sai khác quá nhiều thì sẽ thực hiện rollback và thực hiện lại đúng với thứ tự cần thiết

Conit
* dùng để định nghĩa độ không thống nhất, từ đó để đánh giá độ thống nhất. Cụ thể Conit được coi như tập dữ liệu của kho dữ liệu phân tán. 
* Mức độ thống nhất được xác định theo nhiều mức độ khác nhau
  - Về số lượng các thao tác đã được thực hiện nhưng chưa hoàn thành với số lượng các thao tác chưa được thực hiện trên phần tử dữ liệu
  - Về sai khác của dữ liệu sẽ hoàn thành với dữ liệu đã hoàn thành
* Kích thước Conit
  - lớn -> tăng số lần cập nhật, nhỏ -> giảm số lần cập nhật
  - cần được lựa chọn khi cài đặt
    - nếu số lượng conit ít, kích thước conit lớn -> khả năng xuất hiện sai lệch cao -> chi phí cao -> không hiệu quả với các dữ liệu độc lập. Ví dụ: sau khi có thao tác cập nhật thứ hai thì cần phải tiếp tục cập nhật bản sao 2
    - nếu số lượng conit nhiều, kích thước conit nhỏ -> giảm khả năng xuất hiến ai lệch, chi phí quản lý các bản sao lớn

### 2.3 Mô hình thống nhất theo thứ tự thao tác
Mục tiêu: đạt được thống nhất giữa các dữ liệu chia sẻ. Cụ thể là các dữ liệu được sao lưu (có thể là dữ liệu tập trung, phân tán). Khi thực hiện thao tác, các bản sao phải thống nhất với nhau về một thứ tự thực hiện, vậy sẽ dẫn đến thống nhất với nhau về dữ liệu. Đây được coi là mở rộng của mô hình thống nhất liên tục.

Với các quá trình thực hiện khác nhau, các tiến trình luôn luôn cho một kết quả. Các thao tác trên dữ liệu bao gồm
- Đọc ký hiệu: `R(x)b`
- Ghi ký hiệu: `W(x)a`
- Giá trị khởi tạo của dữ liệu là `nil`

## 3. Mô hình thống nhất hướng người dùng

