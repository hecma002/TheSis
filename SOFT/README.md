# Hướng dẫn thiết lập mô hình và cài đặt các phần mềm, thư viện liên quan

## 1. Cài đặt mô hình
- Mô hình sử dụng 3 máy ảo với 3 vai trò là data-owner, cloud và AA.
- Sử dụng phiên bản Ubuntu18.04

## 2. Cài đặt MySQL
- Thực hiện cài đặt MySQL trên 3 máy theo hướng dẫn của nhà phát hành
- Trên máy chủ đóng vai trò là cloud và data-owner, tạo user cho phép truy cập từ máy chủ đóng vai trò là AA
    - Ở đây nhóm tác giả dùng user `proxy` với passwd là `Aa123456@`
    - Tùy cấu hình máy và mật khẩu, bạn đọc tham khảo file tại source code `../SOURCE/queryMysql.cpp` để chỉnh sửa phù hợp

## 3. Cài đặt thư viện
### 3.1 Cài đặt thư viện mysqlcppconn trên linux
### 3.2 Cài đặt thư viện openABE
- Cài đặt thư viện theo hướng dẫn sau
    1. Clone thư viện
        ```
        git clone https://github.com/zeutro/openabe
        ```
    2. Chỉnh sửa các cài đặt trước khi build
    - Chỉnh sửa file `openabe/deps/gtest/download_gtest.sh`
        - url: `https://github.com/google/googletest/archive/release-${VERSION}.zip` --> `https://github.com/google/googletest/archive/refs/tags/release-${VERSION}.zip`
        - wget option: `wget -O ${GTEST_VERSION} ${GTEST_LINK}` -> `wget -O ${GTEST_VERSION} ${GTEST_LINK} --no-check-certificate`
    - Chỉnh sửa file `openabe/Makefile`: `INSTALL_PREFIX ?= /usr/local` -> `INSTALL_PREFIX ?= $(ZROOT)/build`
    3. Cập nhật các gói cài đặt
    - ```sudo -E ./deps/install_pkgs.sh```
    - ```cd deps/bison/bison-3.3```
    - `sudo ./configure --prefix ~/<your-dir-install>/openabe`
    - `sudo make install`
    4. Cài đặt thư viện: thực hiện tại thư mục gốc của thư viện
    - `. ./env`
    - `make`
    - `make test`
    - `sudo -E make install`
- Copy các file đã build của thư viện vào 2 thư mục
    - Thư mục `../SOURCE/include/openabe` chứa các file header của thư viện
    - Thư mục `../SOURCE/libs/openabe` chứa các file binary của thư viện

