# Quản lý báo cáo định kỳ

Thực hiện sau khi nhiệm vụ đã được xét chọn và đã ký hợp đồng thực hiện.

Thực hiện từ trang quản lý nhiệm vụ HOẶC từ trang danh sách quản lý báo cáo.

## Dựng CSDL

1. QL_BAOCAO_NV

Trường | Kiểu | Ghi chú
--- | --- | ---
ID | int | tự tăng
NHIEM_VU_ID | int |
NGAY_BAO_CAO | datetime | get the day `this` sent to db, not saving draft
KY_BAO_CAO | int | increment with condition
THUC_HIEN_TU_NGAY | datetime | must be larger than the most recent `THUC_HIEN_DEN_NGAY`
THUC_HIEN_DEN_NGAY | datetime | must be larger than `THUC_HIEN_TU_NGAY`
TONG_KINH_PHI | money |
KINH_PHI_NSNN | money |
KINH_PHI_KHAC | money |
PHUONG_THUC_THUC_HIEN | int |
TU_NHAN_XET | ntext |
VAN_DE_TON_TAI | ntext |
DU_KIEN_CONG_VIEC | ntext |
KIEN_NGHI | ntext |

2. BCNV_THUC_HIEN

Trường | Kiểu | Ghi chú
--- | --- | ---
ID | int | tự tăng
BAO_CAO_ID | int |
TYPE | int | xác định kiểu là từ lúc ký hợp đồng HOẶC trong kỳ báo cáo
NOI_DUNG | nvarchar(350) |
STATE | int | xác định trạng thái là đã hoàn thành HOẶC chưa hoàn thành HOẶC đang thực hiện

3. BCNV_KINH_PHI

Trường | Kiểu | Ghi chú
--- | --- | ---
ID | int | tự tăng
BAO_CAO_ID | int |
TYPE | int | xác định cái nào thuộc `Nhà nước` HOẶC `Khác`
TONG_TAT_CA_NHA_NUOC | money |
TONG_TAT_CA_KHAC | money |
TONG_KINH_PHI | money |
TONG_KINH_PHI_TRUOC_BAO_CAO | money |
TONG_KINH_PHI_TRONG_BAO_CAO | money |
TONG_KINH_PHI_NOI_DUNG | money | dùng lại bởi `Khác`
TONG_KINH_PHI_NOI_DUNG_GIAO_KHOAN | money |
TONG_KINH_PHI_NOI_DUNG_KHONG_GIAO_KHOAN | money |
KINH_PHI_UNG_CHI | money | dùng lại bởi `Khác`
KINH_PHI_CHUA_DUNG | money |
TONG_KINH_PHI_KIEM_TRA | money | dùng lại bởi `Khác`
TONG_KINH_PHI_KIEM_TRA_GIAO_KHOAN | money | 
TONG_KINH_PHI_KIEM_TRA_KHONG_GIAO_KHOAN | money | 

4. BCNV_KINH_PHI_TAI_SAN

Trường | Kiểu | Ghi chú
--- | --- | ---
ID | int | tự tăng
BAO_CAO_ID | int |
TEN_TAI_SAN | nvarchar(250) |
NUOC_SAN_XUAT | nvarchar(250) |
THOI_GIAN_BAT_DAU_DUNG | datetime |
SO_HIEU | nvarchar(250) |
DON_VI_TINH | nvarchar(250) |
SO_LUONG | int |
DON_GIA | double |
TONG_TIEN | double |