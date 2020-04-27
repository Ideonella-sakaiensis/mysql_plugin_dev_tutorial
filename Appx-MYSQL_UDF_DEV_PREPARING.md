**April 2020** | **v1.0**

# Mysql UDF Plugin 工作環境設定

-----------------------------------------------------------
### 目錄
  - [for Windows](#for-windows)
  - [for Linux](#for-linux)
    - [CentOS](#centos)
    - [Ubuntu](#ubuntu)
  - [for Mac](#for-mac)
    - [Mac安裝故障排除](#mac%e5%ae%89%e8%a3%9d%e6%95%85%e9%9a%9c%e6%8e%92%e9%99%a4)
      - [若遇到 Homebrew 版本有問題](#%e8%8b%a5%e9%81%87%e5%88%b0-homebrew-%e7%89%88%e6%9c%ac%e6%9c%89%e5%95%8f%e9%a1%8c)
-----------------------------------------------------------

### for Windows
  1. 安裝 MobaXTerm。
      - 下載頁: https://mobaxterm.mobatek.net/download.html
  2. 準備 Ubuntu 18 虛擬機一台。
     1. 虛擬機規格要求:
        1. 4GB RAM or up
        2. 40GB HDD or up
     2. Ubuntu 下載頁: https://www.ubuntu-tw.org/modules/tinyd0/
  3. 啟用 **sshd**，在 Ubuntu 安裝好後，在虛擬機執行，執行以下命令。
      ```bash
      $ sudo apt-get install -y openssh-server
      ```
      ```bash
      $ systemctl enable sshd
      $ systemctl start sshd
      ```
  4. 安裝 **vim**
      ```bash
      $ sudo apt install -y vim
      ```
  5. 安裝 **MariaDB v10+**
      - 安裝指引: https://downloads.mariadb.org/mariadb/repositories/#mirror=weppel
  6. 安裝 **gcc**
      ```bash
      $ sudo apt-get install -y gcc
      ```
  7. 安裝 **MariaDB-Devel**
      ```bash
      $ sudo apt-get install -y libmariadb-dev
      ```

[🔝回目錄](#%e7%9b%ae%e9%8c%84)


### for Linux

#### CentOS
  1. 安裝 **vim**
      ```bash
      $ sudo yum install -y vim
      ```
  2. 安裝 **MariaDB v10+**
      - 安裝指引: https://downloads.mariadb.org/mariadb/repositories/#mirror=weppel
  3. 安裝 **gcc**
      ```bash
      $ sudo yum install -y gcc
      ```
  4. 安裝 **MariaDB-Devel**
      ```bash
      $ sudo yum install -y mariadb-devel
      ```

[🔝回目錄](#%e7%9b%ae%e9%8c%84)


#### Ubuntu
  1. 安裝 **vim**
      ```bash
      $ sudo apt install -y vim
      ```
  2. 安裝 **MariaDB v10+**
      - 安裝指引: https://downloads.mariadb.org/mariadb/repositories/#mirror=weppel
  3. 安裝 **gcc**
      ```bash
      $ sudo apt-get install -y gcc
      ```
  4. 安裝 **MariaDB-Devel**
      ```bash
      $ sudo apt-get install -y libmariadb-dev
      ```

[🔝回目錄](#%e7%9b%ae%e9%8c%84)


### for Mac
  1. 安裝 **MariaDB v10+**
      - 安裝指引: https://mariadb.com/kb/en/installing-mariadb-on-macos-using-homebrew/

      安裝
      ```bash
      brew install mariadb
      ```

      更新 Homebrew
      ```bash
      brew update
      ```

      更新 MariaDB
      ```bash
      brew upgrade mariadb
      ```

      啟動 MariaDB
      ```bash
      mysql.server start
      ```

      設定開機自動啟動 MariaDB
      ```bash
      brew services start mariadb
      ```

  2. 安裝 **gcc**
      ```bash
      brew install gcc
      ```

[🔝回目錄](#%e7%9b%ae%e9%8c%84)


#### Mac安裝故障排除

  ##### 若遇到 Homebrew 版本有問題
  Step 1: 先移除 Homebrew
  ```
  /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/uninstall)"
  ```
  Step 2: 再安裝 Homebrew
  ```
  /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  ```

[🔝回目錄](#%e7%9b%ae%e9%8c%84)
