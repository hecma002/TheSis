# Hướng dẫn thực thi chương trình

- Sau khi cài đặt các thư viện và phần mềm liên quan tại thư mục ``../SOFT``. Thực hiện build chương trình theo file ``../SOURCE/build.sh``
- Trước khi build cần thực hiện bước gán prefix cho chương trình bằng cách
    ```bash
    . ./env
    ```
- Các bước thực hiện chương trình
    - ```./importkey``` để tạo khóa cho các user
    - ```./getdata``` để mã hóa và lưu dữ liệu trên cloud
    - ```./exportuserdata x y``` sử dụng để giải mã và xuất dữ liệu của user y, sử dụng khóa của user x
    - ```./openabe str1 str2``` sử dụng tập khóa `str1` để giải mã đoạn ciphertext `str2`.
- File `thesis.sql` là database mẫu nhóm tác giả sử dụng trong chương trình

