# Bài tập lý thuyết

## Chương 1: Tổng quan về hệ phân tán

> Câu hỏi

Câu hỏi 1: Em hãy nêu thêm 2 ví dụ về dịch vụ được coi là HPT (ngoài 2 ví dụ WWW và Email đã trình bày trên lớp). Dựa vào định nghĩa, giải thích tại sao chúng được coi là HPT.

Câu hỏi 2: Tại sao nói tính chia sẻ tài nguyên của Hệ Phân Tán có khả năng: Giảm chi phí, tăng tính sẵn sàng và hỗ trợ làm việc nhóm? Tuy nhiên lại tăng rủi ro về an toàn thông tin? Giải thích.

Câu hỏi 3: Liên quan đến tính trong suốt, giải thích tại sao nhà quản trị hệ thống phải xem xét việc cân bằng giữa hiệu năng và độ trong suốt? Đưa ra ví dụ cụ thể để giải thích.

Câu hỏi 4: Tại sao giao diện (Interface) lại quan trọng đối với Tính mở của Hệ Phân Tán?

Câu hỏi 5: So sánh 2 kiểu HĐH DOS và NOS. Giải thích tại sao Middleware là sự kết hợp ưu điểm của cả 2 mô hình trên.

Câu hỏi 6: Trình bày về những cơ chế “phân tán” có trong nền tảng Blockchain, ứng dụng vào mô hình sử dụng Bitcoin.

> Trả lời

1. Ví dụ về hệ phân tán:
* Google
* Skype
Giải thích: cả hai ví dụ kể trên đều là hệ phân tán vì 
  * cả hai đều sở hữu các máy chủ là các máy tính độc lập (ở khắp nơi trên thế giới, có phần mềm khác nhau)
  * cung cấp dịch vụ cho người sử dụng như một máy tính duy nhất: Với Google thì cung cấp dịch vụ tìm kiếm, còn Skype cung cấp dịch vụ chat trực tuyến

2. Khi tài nguyên được chia sẻ thì:
  * người dùng có thể sử dụng tài nguyên không nằm trên máy tính của mình nên tiết kiệm được chi phí đầu tư cho
  * khi một máy tính trong hệ thống bị gặp sự cố, máy khác sẽ thay thế máy tính đó thực hiện công việc nên tăng tính sẵn sàng
  * tài nguyên được chia sẻ khắp cho mọi người nên công việc nhóm vì thế dễ dàng thực hiện hơn

Tuy nhiên lại tăng rủi ro về an toàn thông tin vì:
* để chia sẻ tài nguyên thì phải dùng phần mềm chia sẻ và phần mềm ấy phải kết nối mạng, trong phần mềm chắc chắn có những lỗ hổng bảo mật gây ảnh hưởng tới thông tin
* sau một khoảng thời gian, các thông tin về bản thân như vị trí có thể bị tổng hợp và truy lùng, từ đó phát hiện ra thói quen và dễ dàng bị tấn công

3. Vì độ trong suốt càng cao thì chi phí về tiền bạc và thuật toán che giấu càng cao hơn, giải thuật càng phức tạp càng khiến cho thời gian đợi của hệ thống tăng lên và có thể gây ảnh hưởng ít nhiều tới hiệu năng.

Ví dụ: che giấu bản sao lưu (Replication) khỏi người dùng đòi hỏi phía server khi cập nhật sẽ phải gửi yêu cầu thay đổi tới cho client để cập nhật lại toàn bộ hoặc kiểm tra bản sao lưu trên máy cục bộ của người dùng và thay đổi nếu có.
Với một trang học trực tuyến như Udemy có lượng người dùng vào khoảng 1 triệu, vậy mỗi khi sửa lỗi hoặc thông tin hiển thị trên máy chủ sẽ phải gửi yêu cầu tới 1 triệu người dùng đó cùng một lúc, và để làm được điều này, máy chủ sẽ phải ghi nhớ 1 triệu người dùng. Ngoài ra khi có người dùng đang sử dụng dịch vụ có thể khiến cho dịch vụ bị treo do phải render lại toàn bộ trang.

4. Vì nó là phương thức để tương tác giữa các thành phần của hệ thống với nhau, đưa ra quy chuẩn chung đầy đủ, trung lập với mọi công nghệ, nền tảng, hạ tầng; khiến cho việc thêm mới/ thay thế các thành phần của hệ thống đơn giản, dễ dàng.

5. 
* DOS: cho phép các máy tính độc lập kết nối với nhau như một máy tính, tính trong suốt cao
* NOS: cho phép các ứng dụng giao tiếp với nhau, tính trong suốt thấp, chỉ cần hệ điều hành cục bộ hỗ trợ mạng, kiến trúc client-server

Middleware là sự kết hợp ưu diểm của hai mô hình trên vì Middleware:
  * xây dựng trên NOS, áp dụng được với nhiều loại thiết bị
  * bao gồm các dịch vụ thông dụng, hỗ trợ cho người phát triển -> tính trong suốt cao do người dùng chỉ cần gọi đến nó mà không cần biết quá rõ về cấu trúc của nó

6. Cơ chế phân tán của Block-Chain
* chia sẻ tài nguyên: mỗi thiết bị muốn ghi lại khối đều có thể tham gia vào mạng chia sẻ
* tính trong suốt: chỉ lộ phần header, còn lại được mã hoá nhằm che giấu dữ liệu
* tính mở: mỗi khối kế tiếp được tạo ra bởi khối trước đó
* tính co giãn: mọi nơi trên thế giới đều có thể dùng được khối

Áp dụng với Bitcoin
* chia sẻ tài nguyên: mỗi thiết bị đều có thể tham gia đào hoặc lưu trữ bitcoin
* tính trong suốt: người dùng không biết bitcoin được tạo ra từ đâu

## Chương 2: Kiến trúc trong hệ phân tán

Câu 1: Chức năng của từng tầng
* Tầng vật lý: truyền tải dữ liệu thô dưới dạng các tín hiệu điện, sóng...
* Tầng liên kết dữ liệu: truyền dữ liệu giữa các thực thể mạng, phát hiện và sửa lỗi trong tầng vật lý nếu có
* Tầng mạng: xác định đường đi tốt nhất cho các gói tin
* Tầng giao vận: chuyển dữ liệu giữa các người dùng tại đầu cuối
* Tầng phiên: thiết lập, duy trì và kết thúc các phiên làm việc giữa hai bên
* Tầng trình diễn: chuyển đổi dữ liệu từ tầng ứng dụng gửi xuống, mã hoá, nén dữ liệu trước khi truyền đi
* Tầng ứng dụng: cung cấp giao diện cho người dùng với tài nguyên

Chẳng hạn: khi chuyển IPv4 sang IPv6 thì dữ liệu vẫn truyền thông bình thường.

Câu 2: Khi nhắn tin trong messenger của Facebook, khi người dùng nhập một tin gì đó có thông điệp muốn mua một loại mặt hàng. Facebook sẽ gửi quảng cáo lên trang của người dùng về mặt hàng đó.
- Publisher là Facebook
- Subcriber là người dùng
- Loại ở đây là content-based

Câu 3:
* Phân tán dọc: chia các chức năng cho từng nút trong hệ thống
* Phân tán ngang: chia nhỏ một chức năng thành nhiều công việc tương đương nhau cho từng nút trong hệ thống

Câu 4:
Kiến trúc tập trung:
* Ưu điểm
  - Tăng hiệu năng qua các giao diện người dùng
  - Tích hợp nhiều dịch vụ trên các nền tảng khác nhau
  - Đảm bảo tính toạn vẹn của dữ liệu, độ tin cậy
* Nhược điểm
  - Có thể bị quá tải khi có quá nhiều lượt truy cập cùng lúc
  - Nếu một máy chủ gặp sự cố, các yêu cầu từ phía người dùng sẽ không được thực hiện (tuỳ theo cách xây dựng)

Kiến trúc không tập trung
* Ưu điểm:
  - Dễ cài đặt và cấu hình
  - Tất cả nội dung đều được chia sẻ ngang hàng trên mọi máy, không phụ thuộc
* Nhược điểm:
  - Khó quản lý
  - Khó sao lưu, phục hồi dữ liệu

Câu 5: Nhược điểm quan trọng của mạng overlay tập trung, topology là độ trễ lớn bởi việc truyền qua mỗi node đều phải xác định định tuyến -> khoảng cách giữa các node trên tầng vật lý có thể xa hơn trên tầng overlay, vì thế sẽ phải định tuyến qua nhiều node để truyền được tin

Câu 6: Vấn đề:
* nếu một tiến trình gặp sự cố -> yêu cầu không được thực hiện 
* độ trễ trả về phản hồi lớn do có nhiều tầng xếp chồng lên nhau

Câu 7: Giải thuật là tốt bởi nó chỉ phụ thuộc vào hàm băm, hình học mà không phải xem xét đến việc định tuyến trên hình trạng mạng (topology)

## Chương 3: Tiến trình và luồng
> Câu hỏi
Câu hỏi 1: Có cần thiết phải giới hạn số lượng các luồng trong một tiến trình server?

Câu hỏi 2: Có nên chỉ gắn một luồng đơn duy nhất với một tiến trình nhẹ?

Câu hỏi 3: Có nên chỉ có một tiến trình nhẹ đơn gắn với 1 tiến trình?
Câu hỏi 4: Bài toán này yêu cầu bạn so sánh thời gian đọc một tệp (file) của một máy chủ tập tin (file server) đơn luồng và một máy chủ đa luồng. Phải mất tổng cộng 15 ms để nhận 1 yêu cầu (request) và thực hiện quá trình xử lý, giả định rằng các dữ liệu cần thiết nằm ở bộ nhớ đệm trong bộ nhớ chính. Nếu cần thiết phải thực hiện một thao tác truy cập ổ đĩa thì cần thêm 75 ms, biết rằng việc phải thực hiện thao tác này có xắc suất là 1/3. Hỏi máy chủ có thể nhận bao nhiêu yêu cầu/giây trong 2 trường hợp: máy chủ là đơn luồng và máy chủ là đa luồng (ngoài luồng nhận và xử lý request, sẽ có thêm 1 luồng để truy cập ổ đĩa nếu cần thiết)? Giải thích.

Câu hỏi 5: Hệ thống X chỉ định máy của user chưa server, trong khi các ứng dụng lại được coi như client. Điều đó có vô lý không? Giải thích.

Câu hỏi 6: Giao thức thiết kế cho hệ thống X gặp phải vấn đề về tính mở rộng. Chỉ ra các giải pháp để giải quyết vấn đề đó?

Câu hỏi 7: Với việc xây dựng một server đồng thời, hãy so sánh việc server này tạo một luồng mới và tạo một tiến trình mới khi nhận được yêu cầu từ phía client. 

Câu hỏi 8: Nếu bây giờ một webserver tổ chức lưu lại thông tin về địa chỉ IP của client và trang web client đó vừa truy cập. Khi có 1 client kết nối với server đó, server sẽ tra xem trong bảng thông tin, nếu tìm thấy thì sẽ gửi nội dung trang web đó cho client. Server này là có trạng thái (stateful) hay không trạng thái (stateless)?

Câu hỏi 9: So sánh Docker và Virtual Machine. 

> Trả lời

1. Có, vì tài nguyên hệ thống có hạn và khả năng xử lý của các luồng cũng vậy.

2. Không, vì nếu luồng bị dừng thì tiến trình nhẹ sẽ không thể đảo công việc tới một luồng khác.

3. Không, vì một tiến trình sinh ra nhiều luồng, cần có nhiều tiến trình nhẹ để quản lý các luồng đó.

4. Khó thế bố thằng nào biết được

5. Không. Vì hệ thống di trú một phần mã của server xuống client để tăng tốc, và khi thực hiện xong một hành động nào đó, các client vẫn phải chuyển yêu cầu lên server chính, nên chúng không bị nhập nhằng.

6. Thực hiện ảo hoá 

7. 

8. CÓ

9. Mọi ứng dụng đều phải chạy trên OS tương ứng của VM
Docker tạo sẵn môi trường chạy cho các ứng dụng.