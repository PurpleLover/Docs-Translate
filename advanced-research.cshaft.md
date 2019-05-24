# GHi chú về việc tìm hiểu các kỹ thuật và ứng dụng liên quan

## Elastic Search

Mọi phần mềm trong Elastic Stack đều phải trùng phiên bản với nhau (ví dụ ES 6.1 thì Kibana cũng phải 6.1).

Để chạy được ES cần phải có JVM trong khoảng từ 1.8.0_111 đổ lên (phiên bản LTS). Setup path chuẩn.

Khi cài hãy chọn cài thành Service của Windows để nó khởi động cùng Windows.

Nếu dùng cho .NET thì sử dụng 2 thư viện đã viết sẵn cho nền tảng này là:
* Elasticsearch-net: low-level
* NEST: high-level
2 thư viện trên muốn dùng phải cùng phiên bản với nhau và cùng phiên bản với ES.

## Multithreading trong .NET

Hiện tại đang phân vân giữa chia Thread và Async/Await.

Với Async/Await thì dùng trả về Task và làm gần như tương tự với Promise.

Với Thread, dùng các syntax trên mạng. Cách dùng sẽ cập nhật sau.

## Tài liệu tham khảo
### Căn bản
* [Async/Await trong MVC 4](https://docs.microsoft.com/en-us/aspnet/mvc/overview/performance/using-asynchronous-methods-in-aspnet-mvc-4)
* [Tổng hợp lập trình song song trong C#](https://docs.microsoft.com/en-us/dotnet/standard/parallel-programming/index)
* [Hướng dẫn căn bản về Thread trong C#](https://o7planning.org/vi/10553/huong-dan-lap-trinh-da-luong-trong-csharp)
* [Pass more data to Thread](https://stackoverflow.com/questions/14854878/creating-new-thread-with-method-with-parameter)

### Under the hood
* [Async/Await vs. Thread or When to use?](https://stackoverflow.com/questions/15148852/async-await-vs-threads)
* [Do Async/Await take up Threadpool](https://stackoverflow.com/questions/8743067/do-asynchronous-operations-in-asp-net-mvc-use-a-thread-from-threadpool-on-net-4)
* [Understand more about Threading](http://www.albahari.com/threading/)

### Interesting tool
* [Calc exec-time with stop-watch](https://stackoverflow.com/questions/14019510/calculate-the-execution-time-of-a-method)
* [Test and tune LinQ](http://www.linqpad.net/EntityFramework.aspx)
