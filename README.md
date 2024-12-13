# Soket-program-

# Taş-Kağıt-Makas Sunucu ve İstemci Uygulaması

Bu proje, C programlama dili kullanılarak geliştirilmiş bir taş-kağıt-makas oyunudur. Uygulama, sunucu-istemci mimarisinde çalışır ve TCP/IP protokolü üzerinden iletişim kurar. Proje iki ana bileşenden oluşmaktadır:

   <h3>1. Sunucu (Server):<h3>
      Gelen istemci bağlantılarını yönetir, istemcilerden gelen hamlelere karşılık verir ve oyunun skorlarını tutar.
  <h3> 2. İstemci (Client):<h3>
     Kullanıcıdan hamle alır ve bu hamleleri sunucuya gönderir, ardından sunucudan gelen cevapları görüntüler.
     
<h3>Kullanılan Teknolojiler ve Dil Özellikleri<h3>
   -<h2>Programlama Dili:<h2> C
   -<h2>Kütüphaneler:<h2>
   -<h2>winsock2.h:<h2> Windows işletim sistemi için TCP/IP soket programlamayı destekler.
   -<h2>time.h:<h2> Rastgele sayı üretimi ve zamanla ilgili işlemler için kullanılır.
   -<h2>utils.h:<h2> Geçerli hamle kontrolü, küçük harfe çevirme ve kazananı belirleme gibi ortak    -      -işlevleri içerir.
   -<h2>Protokol:<h2> TCP/IP
<h2>İstemci-Sunucu İletişimi: <h2>Sunucu, birden fazla istemciyi eşzamanlı olarak işlemek için iş parçacıklarını (CreateThread) kullanır.
Sunucu (Server)
Sunucu programı şu işlevleri yerine getirir:

Başlatma ve Dinleme:

bind ile belirli bir IP ve port üzerinden bağlanır.
listen komutuyla istemci bağlantılarını bekler.
Bağlantı Yönetimi:

Gelen her istemci bağlantısı için bir iş parçacığı oluşturulur.
Bağlantı sırasında istemciden gelen mesajlar okunur ve işlenir.
Oyun Mantığı:

Gelen hamlelerin geçerliliğini kontrol eder.
Sunucunun rastgele bir hamle yapmasını sağlar.
Hamleleri karşılaştırarak kazananı belirler.
Skorları takip eder ve istemciye sonuçları gönderir.
Komutlar:

yardim: Geçerli komutları listeler.
skor: O anki oyuncu ve sunucu skorlarını gösterir.
exit: İstemci bağlantısını sonlandırır.
Öne Çıkan Özellikler:
Birden fazla istemciyi desteklemek için çoklu iş parçacığı yönetimi.
Skor takibi için Score yapısı kullanımı.
Geçersiz hamleleri tespit ederek uygun mesaj gönderimi.
İstemci (Client)
İstemci programı şu işlevleri yerine getirir:

Bağlantı Kurma:

Sunucuya bağlanır ve kullanıcı hamlelerini sunucuya gönderir.
Kullanıcı Etkileşimi:

Kullanıcıdan hamle alır: tas, kagit, makas, yardim, skor, exit.
Sunucudan gelen mesajları okur ve ekrana yazdırır.
Oyun Akışı:

Kullanıcı her hamle yaptığında, sunucu ile iletişim kurar ve sonucu gösterir.
Nasıl Çalıştırılır?
Sunucuyu Başlatma
Derleme:
sh
Kodu kopyala
gcc -o server server.c -lws2_32
Çalıştırma:
sh
Kodu kopyala
./server
İstemciyi Başlatma
Derleme:
sh
Kodu kopyala
gcc -o client client.c -lws2_32
Çalıştırma:
sh
Kodu kopyala
./client
Oyun Komutları
tas, kagit, makas: Oyuncunun yapacağı hamle.
yardim: Kullanılabilir komutları gösterir.
skor: Oyuncunun ve sunucunun skorlarını gösterir.
exit: Oyundan çıkış yapar.
