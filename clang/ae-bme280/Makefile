
CC = gcc
OBJS = ae-bme280.o
PROG = ae-bme280

# インクルードファイルのディレクトリパス
# /usr/include以外のヘッダファイルを参照させる時に使う。
# INCDIR  = -I/usr/local/include
INCDIR =
 
# ライブラリファイルのディレクトリパス
# /usr/lib以外のライブラリを参照させる場合に使う。
#LIBDIR = -L/usr/local/lib
LIBS+= -lwiringPi

CFLAGS = -Wall

# デバッグ時は「CFLAGS+= -O2」をコメントにして
# 「#CFLAGS+= -g -O0」を有効にします。
#CFLAGS+= -O2
CFLAGS+= -g -O0

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

$(PROG): $(OBJS)
	$(CC) $(LIBDIR) $(LIBS) -o $(PROG) $^

# サフィックスルール
.c.o:
	$(CC) $(INCDIR) $(CFLAGS) -c $<

# ファイル削除用ターゲット
.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS) a.out TAGS tags

cleandir:
	rm -f $(PROG) $(OBJS) a.out TAGS tags *core *~

