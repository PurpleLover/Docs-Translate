# Trang 18

## Chỉ mục chậm, phần II

Phần trước đã giải thích cách để đạt được thêm lợi ích từ chỉ mục đã tồn tại thông qua thay đổi thứ tự cột của nó, nhưng ví dụ chỉ tập trung trên hai câu lệnh SQL. Tuy nhiên, việc thay đổi một chỉ mục có thể làm ảnh hưởng tới tất cả các câu truy vấn trong bảng đã đánh chỉ mục. Phần này giải thích cách cơ sở dữ liệu lựa chọn một chỉ mục và chứng minh tác dụng phụ có thể xảy đến khi thay đổi chỉ mục đã tồn tại.

Chỉ mục con `EMPLOYEE_PK` cải thiện hiệu năng của tất cả các câu truy vấn mà chỉ tìm kiếm bổ trợ. Tuy nhiên, nó cũng hữu dụng cho tất cả các câu truy vấn mà tìm kiếm thông qua `SUBSIDIARY_ID` (ID bổ trợ) - vốn không cần quan tâm xem liệu có thêm tiêu chí tìm kiếm nào hay không. Tức là chỉ mục trở nên hữu dụng cho câu truy vấn nào từng dùng một chỉ mục khác với phần khác trong mệnh đề **where**. Trong trường hợp đó, nếu tồn tại nhiều hướng truy xuất, thì bộ tối ưu hoá phải chọn ra hướng tốt nhất.

---
### Bộ tối ưu hoá câu truy vấn

Bộ tối ưu hoá câu truy vấn, hay là bộ hoạch địch chiến lược câu truy vấn, là thành phần của cơ sở dữ liệu, chuyển đổi câu lệnh SQL thành chiến lược thực thi. Quá trình này được gọi là _biên dịch_ hoặc _phân tích ngữ pháp_. Có hai kiểu tối ưu hoá chuyên biệt.

_Tối ưu hoá dựa theo chi phí_ (CBO) sinh ra nhiều chiến lược thực thi và tính toán _chi phí_ cho từng chiến lược. Tính toán chi phí dựa trên phép toán được dùng và số dòng ước lượng. Sau cùng, giá trị chi phí được dùng như tiêu chuẩn để chọn ra chiến lược "tốt nhất".

_Tối ưu hoá dựa theo luật_ (RBO) sinh ra chiến lược thực thi bằng cách sử dụng bộ luật cứng. Bộ tối ưu hoá dựa theo luật ít linh hoạt hơn và ngày nay hiếm được dùng.

###
---

# Trang 19

Thay đổi chỉ mục cũng có thể gây ra tác dụng phụ không mong muốn. Trong ví dụ của chúng ta, ứng dụng thư mục điện thoại trở nên cực kì chậm kể từ khi được hợp lại. Phân tích ban đầu ác định câu truy vấn dưới đây chính là lý do gây ra sự chậm trễ:


---
```
SELECT first_name, last_name, subsidiary_id, phone_number
FROM employees
WHERE last_name  = 'WINAND'
AND subsidiary_id = 30;
```
---

Chiến lược thực thi là:

**Ví dụ 2.1. Chiến lược Thực thi với Chỉ mục Khoá chính đã Sửa đổi**

---

Ví dụ trong sách trang 19

---

Chiến lược thực thi sử dụng một chỉ mục và có giá trị chi phí bao quát là 30. Cơ bản thì, khá ổn. Tuy nhiên, có nghi ngờ cho rằng nó sử dụng chỉ mục mà ta vừa thay đổi - vậy là đủ lý do để nghi ngờ rằng sự thay đổi chỉ mục của chúng ta nảy sinh vấn đề hiệu năng, liên quan tới định nghĩa chỉ mục cũ - nó bắt đầu với cột `EMPLOYEE_ID` vốn không phải một phần của mệnh đề **where**. Câu truy vấn không thể sử dụng chỉ mục đó được.

Phân tích sâu hơn, sẽ tốt hơn nếu ta so sánh chiến lược thực thi trước và sau sự thay đổi. Đế lấy lại chiến lược thực thi ban đầu, ta có thể chỉ cần triển khai lại định nghĩa của chỉ mục cũ thêm lần nữa, tuy nhiên hầu hết các cơ sở dữ liệu dùng phương thức đơn giản hơn để ngăn ngừ sử dụng một chỉ mục cho một truy vấn nhất định. Ví dụ dưới đây sử dụng _bộ diễn giải tối ưu hoá_ của Oracle để đoạt được mục đích đó.

---
```
SELECT /*+ NO_INDEX(EMPLOYEES EMPLOYEE_PK) */ first_name, last_name, subsidiary_id, phone_number
FROM employees
WHERE last_name  = 'WINAND'
AND subsidiary_id = 30;
```
---

# Trang 20

Chiến lược thực thi được dùng trước khi chỉ mục thay đổi không hề sử dụng một chỉ mục nào:

---

Ví dụ trong sách trang 20

---

Mặc dù `TABLE ACCESS FULL` phải đọc và thực thi cả bảng, dường như sử dụng nó trong trường hợp này lại nhanh hơn là dùng chỉ mục. Điều đó thật khó chấp nhận bởi vì câu truy vấn chỉ trả về một hàng duy nhất. Sử dụng chỉ mục để tìm kiếm một hàng riêng biệt đáng ra phải nhanh hơn so với quét cả bảng, nhưng trong trường hợp này thì không. Chỉ mục có vẻ lại chậm hơn.

Trong những trường hợp như vậy, tốt nhất là đi qua từng bước để do thám chiến lược thực thi. Bước đầu tiên là với `INDEX RANGE SCAN` trên chỉ mục `EMPLOYEE_PK`. Chỉ mục đó không bao hàm cột `LAST_NAME` - `INDEX RANGE SCAN` chỉ có thể xác định được bộ lọc `SUBSIDIARY_ID`; cơ sở dữ liệu của Oracle chỉ ra điều này trong phần "Predicate Information" (tạm dịch là "Thông tin Vị từ") - mục "2" trong chiến lược thực thi. Như bạn có thể thấy, đó là điều kiện để áp dụng cho từng phép toán.

---
### Mẹo

Phụ lục A, _"Chiến lược thực thi"_, giải thích cách tìm "Thông tin Vị từ" cho các cơ sở dữ liệu khác.
---

`INDEX RANGE SCAN` với phép toán `ID 2` (Ví dụ 2.1 trên trang 19) chỉ áp dụng với bộ lọc `SUBSIDIARY_ID =30`. Tức là nó cắt ngang cây chỉ mục để tìm ra mục đầu tiên thoả mãn `SUBSIDIARY_ID 30`. Kế đến nó di chuyển qua chuỗi nút lá nối tiếp nhau để tìm tất cả các mục khác phù hợp chỉ mục bổ trợ ấy. Kết quả trả về của `INDEX RANGE SCAN` là một danh sách các `ROWID` thoả mãn điều kiện của `SUBSIDIARY_ID`: tuỳ thuộc vào kích thước của chỉ mục bổ trợ, có thể sẽ có một vài cho tới vài trăm `ROWID`.

Bước kế tiếp là phép toán `TABLE ACCESS BY INDEX ROWID`. Nó dùng các `ROWID` vừa tìm được trong bước liền trước để gọi ra các dòng - tất cả các cột - từ bảng. Ngay khi cột `LAST_NAME` sẵn sàng, cơ sở dữ liệu có thể tính toán nốt phần còn lại trong mệnh đề **where**. Điều đó có nghĩa là cơ sở dữ liệu phải gọi ra tất cả các hàng phù hợp với `SUBSIDIARY_ID=30` trước khi áp dụng bộ lọc cho `LAST_NAME`.

# Trang 21

Thời gian phản hồi của câu lệnh không phụ thuộc vào kích thước của tập giá trị mà phụ thuộc số lượng nhân viên có trong mỗi khu vực con nhất định. Nếu khu vực đó chỉ có vài bản ghi, `INDEX RANGE SCAN` có hiệu năng tốt hơn. Ngược lại, `TABLE ACCESS FULL` có thể nhanh hơn trên khu vực có mật độ dày bởi vì nó có thể đọc các phần to từ bảng trong một lượt (xem "Full Table Scan" trong trang 13).

Câu truy vấn bị chậm bởi quá trình duyệt chỉ mục trả về nhiều `ROWID` - mỗi `ROWID` tương ứng với một nhân viên trong công ty - và cơ sở dữ liệu phải gọi đến từng thằng một. Hai yếu tố hoàn hảo kết hợp lại với nhau khiến cho chỉ mục bị chậm: cơ sở dữ liệu đọc một khoảng rộng các chỉ mục và phải gọi ra lần lượt từng hàng.

Việc lựa chọn chiến lược thực thi tốt nhất phụ thuộc vào sự phân bố dữ liệu trên bảng thế nên bộ tối ưu hoá sử dụng thống kê nội dung của cơ sở dữ liệu. Ví dụ của chúng ta sử dụng biểu đồ biểu thị sự phân bổ nhân viên trên các khu vực con. Cái này cho phép bộ tối ưu hoá ước lượng số lượng hàng trả về nếu duyệt chỉ mục - kết quả được dùng cho việc tính toán chi phí.

---
### Thống kê

Bộ tối ưu hoá dựa trên chi phí sử dụng thống kê về bảng, cột, và chỉ mục. Hầu hết các thống kê được thu gom theo cấp độ của cột: số lượng giá trị riêng biệt, giá trị lớn nhất và nhỏ nhất (theo miền dữ liệu), số lần `NULL` xuất hiện và biểu đồ cột (phân bố dữ liệu). Giá trị thống kê quan trọng nhất cho một bảng là kích thước của nó (theo hàng và khối).

Số liệu thống kê chỉ mục quan trọng nhất là độ sâu của cây, số lượng nút lá, số lượng khoá riêng biệt và hệ số phân nhóm (xem Chương 5 _"Dữ liệu phân nhóm"_).

Bộ tối ưu hoá sử dụng những giá trị này để ước lượng tính chọn lọc của các vị từ trong mệnh đề **where**.

---

# Trang 22

Nếu không có thống kê nào có sẵn - chẳng hạn chúng bị xoá sạch - bộ tối ưu hoá sử dụng giá trị mặc định. Thống kê mặc định của cơ sở dữ liệu Oracle nối một chỉ mục nhỏ với tính lựa chọn trung bình. Thành ra nó ước lượng rằng `INDEX RANGE SCAN` sẽ trả về 40 dòng. Chiến lược thực thi biểu thị giá trị ước lượng này trong cột `Rows` (hãy xem lại Ví dụ 2.1 trong trang 19). Hiển nhiên đây là đánh giá tổng quát, bởi có tới 1000 nhân viên làm việc trong khu vực con này.

Nếu ta cung cấp số liệu thống kê chuẩn xác, bộ tối ưu hoá làm việc tốt hơn. Chiến lược thực thi dưới đấy hiển thị ước lượng mới: 1000 hàng cho `INDEX RANGE SCAN`. Cứ thế nó tính toán ra chi phí cao nhất cho việc truy xuất bảng kế tiếp.

Chi phí có giá trị là 680, thậm chí cao hơn cả chi phí cho chiến lược thực thi sử dụng `FULL TABLE SCAN` (477, xem trang 20). Vì thế bộ tối ưu hoá sẽ tự động lựa chọn `FULL TABLE SCAN`.

Ví dụ về chỉ mục chậm không nên giấu đi sự thực về việc đánh chỉ mục chuẩn xác là giải pháp tốt nhất. Đương nhiên để tìm keiesm được bằng tên họ, thì ta phải tạo chỉ mục cho `LAST_NAME`.

# Trang 23

Sử dụng chỉ mục mới, bộ tối ưu hoá tính toán ra giá trị chi phí là 3:

---

Ví dụ 2.2. Chiến lược Thực thi với Chỉ mục Chuyên biệt

---

Truy xuất chỉ mục mang tới - dựa theo ước lượng của bộ tối ưu - một dòng duy nhất. Cơ sở dữ liệu chỉ phải gọi đến đúng dòng đó trong bảng: điều này chắc chắn nhanh hơn nhiều so với `FULL TABLE SCAN`. Một chỉ mục được định nghĩa chuẩn xác vẫn luôn nhỉnh hơn hẳn quét nguyên cả bảng.

Hai chiến lược thực thi trong Ví dụ 2.1 (trang 18) và Ví dụ 2.2 khá giống nhau. Mặc dù cơ sở dữ liệu đều thi hành cùng phép toán và bộ tối ưu hoá tính toán ra chi phí tương đương nhau, chiến lược thứ hai thi hành tốt hơn rất nhiều. Hiệu năng của `INDEX RANGE SCAN` có thể phụ thuộc vào nhiều yếu tố - đặc biệt là khi kéo theo truy xuất bảng. Sử dụng chỉ mục không tự động khiến một câu lệnh nào đó thực thi theo cách tốt nhất.