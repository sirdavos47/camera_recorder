# camera_recorder
embedded app for recording ip camera streams

## Yeni Özellikler

### 1. Hareket Algılama ile Kayıt (Motion Detection Recording)
Kamera görüntüsünde hareket algılandığında otomatik olarak kayda başlar. Hareket bittiğinde kaydı durdurur.

**Kullanım:**
```
./camera_recorder motion_record <ip_kamera_url> <kayit_dosyasi.avi>
```

### 2. Anlık Ekran Görüntüsü Alma (Snapshot)
Canlı izleme sırasında tek tuşla ekran görüntüsü alır ve dosyaya kaydeder.

**Kullanım:**
```
./camera_recorder snapshot <ip_kamera_url> <gorsel_dosyasi.jpg>
```

### 3. Kayıt Zamanlayıcı (Scheduled Recording)
Belirli bir süre boyunca veya belirli bir saatte otomatik kayıt başlatır ve durdurur.

**Kullanım:**
```
./camera_recorder schedule_record <ip_kamera_url> <kayit_dosyasi.avi> <sure_saniye>
```

### 4. Kayıt Boyutu ve Süresi Limiti
Kayıt dosyasının maksimum boyutunu veya süresini belirleyerek, limit aşıldığında kaydı otomatik durdurur.

**Kullanım:**
```
./camera_recorder record <ip_kamera_url> <kayit_dosyasi.avi> --max-size 100MB --max-duration 600
```

### 5. Kayıt Sırasında Sesli Uyarı (Beep)
Kayıt başlarken ve biterken sesli uyarı verir.

**Kullanım:**
Otomatik olarak çalışır, ek bir parametre gerekmez.

---

Her özellik için kod desteği eklenebilir. Kod dosyalarınız tekrar erişilebilir olursa, bu özelliklerin kodunu da ekleyebilirim.
