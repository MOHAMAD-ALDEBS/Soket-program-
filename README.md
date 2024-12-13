# Taş-Kağıt-Makas Sunucu ve İstemci Uygulaması

Bu proje, C programlama dili kullanılarak geliştirilmiş bir taş-kağıt-makas oyunudur. Uygulama, sunucu-istemci mimarisinde çalışır ve TCP/IP protokolü üzerinden iletişim kurar. Proje iki ana bileşenden oluşmaktadır:

1. **Sunucu (Server)**: Gelen istemci bağlantılarını yönetir, istemcilerden gelen hamlelere karşılık verir ve oyunun skorlarını tutar.
2. **İstemci (Client)**: Kullanıcıdan hamle alır ve bu hamleleri sunucuya gönderir, ardından sunucudan gelen cevapları görüntüler.

## Kullanılan Teknolojiler ve Dil Özellikleri

- **Programlama Dili**: C
- **Kütüphaneler**:
  - `winsock2.h`: Windows işletim sistemi için TCP/IP soket programlamayı destekler.
  - `time.h`: Rastgele sayı üretimi ve zamanla ilgili işlemler için kullanılır.
  - `utils.h`: Geçerli hamle kontrolü, küçük harfe çevirme ve kazananı belirleme gibi ortak işlevleri içerir.
- **Protokol**: TCP/IP
- **İstemci-Sunucu İletişimi**: Sunucu, birden fazla istemciyi eşzamanlı olarak işlemek için iş parçacıklarını (`CreateThread`) kullanır.

## Sunucu (Server)

Sunucu programı şu işlevleri yerine getirir:

1. **Başlatma ve Dinleme**:
   - `bind` ile belirli bir IP ve port üzerinden bağlanır.
   - `listen` komutuyla istemci bağlantılarını bekler.

2. **Bağlantı Yönetimi**:
   - Gelen her istemci bağlantısı için bir iş parçacığı oluşturulur.
   - Bağlantı sırasında istemciden gelen mesajlar okunur ve işlenir.

3. **Oyun Mantığı**:
   - Gelen hamlelerin geçerliliğini kontrol eder.
   - Sunucunun rastgele bir hamle yapmasını sağlar.
   - Hamleleri karşılaştırarak kazananı belirler.
   - Skorları takip eder ve istemciye sonuçları gönderir.

4. **Komutlar**:
   - `yardim`: Geçerli komutları listeler.
   - `skor`: O anki oyuncu ve sunucu skorlarını gösterir.
   - `exit`: İstemci bağlantısını sonlandırır.

### Öne Çıkan Özellikler

- Birden fazla istemciyi desteklemek için çoklu iş parçacığı yönetimi.
- Skor takibi için `Score` yapısı kullanımı.
- Geçersiz hamleleri tespit ederek uygun mesaj gönderimi.

## İstemci (Client)

İstemci programı şu işlevleri yerine getirir:

1. **Bağlantı Kurma**:
   - Sunucuya bağlanır ve kullanıcı hamlelerini sunucuya gönderir.

2. **Kullanıcı Etkileşimi**:
   - Kullanıcıdan hamle alır: `tas`, `kagit`, `makas`, `yardim`, `skor`, `exit`.
   - Sunucudan gelen mesajları okur ve ekrana yazdırır.

3. **Oyun Akışı**:
   - Kullanıcı her hamle yaptığında, sunucu ile iletişim kurar ve sonucu gösterir.
