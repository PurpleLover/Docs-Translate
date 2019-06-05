# Giới thiệu

Folder này chứa các nội dung bài giảng mà mình note lại trong lúc học môn hệ phân tán ở SIE.

Vì là note nên có vài chỗ hơi nhiều, vài chỗ hơi ít.

## Phân chia mục

Folder `docx_export` chứa các bản printable (hay còn gọi là khả in). Tức là chứa các bản doc. Bao gồm cho từng topic và một bản cuối đầy đủ. Hãy dùng IQ của mình để tìm ra bản đó nhé.

Folder `images` chứa các mục ảnh dùng trong các ví dụ trong topic. Các folder con tương ứng với từng topic.

Các file `.md` là các file note của mình. Sau này mình sẽ tổng hợp lại để đầy đủ note hơn. Riêng file `exercise` và `tracnghiem` chỉ chứa bài tập lý thuyết và trắc nghiệm tương ứng. Những file này cũng rất hạn chế câu hỏi.

## Pandoc

Nếu bạn muốn tự phóng thích mấy thằng markdown thành docx hoặc đổi định dạng khác thì hãy cài `pandoc`. Cách cài thì tự google nhé.

Cách dùng:

- Clone folder này về
- cd vào folder chứa file (hoặc mở folder đó bằng visual code và chọn vào terminal dựng sẵn)
- Gõ lệnh `pandoc -o ten_file_dich.dinh_dang ten_file_goc.dinh_dang`

Ví dụ: `pandoc -o topic11.docx topic11.md`