## Topic 6
Câu hỏi 1: Trong các giao thức phân tầng, mỗi tầng có header riêng của mình để gắn vào gói tin. Có một cách làm khác là tổng hợp tất cả các phần đầu gói tin vào làm một header duy nhất cho tất cả các tầng. Tại sao cách này không được áp dụng?
- Mỗi tầng phải độc lập với các tầng khác
- Làm mất tính trong suốt giữa các tầng 
- Mọi thay đổi trong một tầng sẽ khiến tầng khác biết được

Câu hỏi 2: Trong giao thức yêu cầu trả lời, server có gửi thông điệp báo nhận cho client không? Tại sao?
> Không, bởi vì thông điệp trả lời cũng đóng vai trò của một thông điệp đón nhận

Câu hỏi 3: Trong truyền thông socket, server có biết trước cổng socket của client trước khi nhận được yêu cầu hay không?
> không, server chỉ biết sau khi nhận được yêu cầu

Câu hỏi 4: Vai trò của Message Broker trong hệ thống hàng đợi thông điệp là gì?
> chuyển định dạng của thông điệp đầu vào để các ứng dụng khác hiểu được

## Topic 11

Câu hỏi 1: Có bao nhiêu thông điệp trong giải thuật phân tán trong việc loại trừ lẫn nhau?
> 2(n-1) với n là số tiến trình

Câu hỏi 2: Giải thuật vòng cho loại trừ lẫn nhau gặp phải những vấn đề gì?
> mất token, treo tiến trình

Câu hỏi 3: Hai lý do chính của sao lưu?
> Tin cậy và hiệu năng

Câu hỏi 4: Conit là gì?
> Đơn vị tính toán tính thống nhất

## Topic 12

Câu hỏi 1: Các điểm yếu của đồng bộ hoá tạm thời là gì?
> Chất lượng thấp, nhất là với dịch vụ thời gian thực

Câu hỏi 2: Đơn điệu đọc là gì?
> Nếu một tiến trình đọc dữ liệu x ở một thời điểm, thì mọi tiến trình đọc trên x của tiến trình này sẽ trả về cùng một giá trị hoặc giá trị gần nhất

Câu hỏi 3: Hướng tiếp cận dựa trên push là gì?
> Cập nhật dữ liệu lên bản sao lưu khi bản sao lưu không đòi hỏi cập nhật

Câu hỏi 4: Đâu là 2 ràng buộc của số lần đọc và ghi Quorum
> Nr + Nw > N và Nw > N/2

## Topic 13

Câu hỏi 1: Chỉ ra 3 khả năng của việc truyền bản cập nhật cho các server bản sao?
> chỉ thông báo khi có cập nhật, truyền dữ liệu cập nhật, truyền thao tác cập nhật

Câu hỏi 2: Vấn đề của giao thức ghi từ xa?
> có thể mất tương đối nhiều thời gian để tiến trình cập nhật

Câu hỏi 3: Lỗi sụp đổ là gì?
> Server tạm dừng nhưng vẫn hoạt động cho tới khi bị oẳng

Câu hỏi 4: Vấn đề chính của phản hồi phân cấp là gì?
> Xây dựng hệ thống động không dễ
