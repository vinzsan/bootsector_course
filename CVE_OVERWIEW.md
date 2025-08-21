# Overview (2025-08-21 : 09:50)
# Note()

## 1. Ringkasan Teknis

WhatsApp menggunakan protokol Peer-to-Peer ama End-to-End Encryption _E2EE_ untuk komunikasi langsung antar devices. arsitektur scr efektif hide IP addr client, tapi potensi kerentanan tetap ada yaw. sejarah CVE nya nunjukin kalau mitigasi telah dilakukan, dan vuln baru bisa muncul lgi.

## 2. CVE Terkait WhatsApp (2023–2025->future?)

### 2.1 CVE-2023-38538 Overview journal github.com/vinzsan : vuln_wa_me_threadvuln : in -> markdown

* **Deskripsi**: Kondisi balapan (*race condition*) pada subsistem event menyebabkan *heap use-after-free* dalam panggilan audio/video yang sudah terhubung, berpotensi menghentikan aplikasi atau menyebabkan alur kontrol tak terduga.
* **Dampak**: Potensi crash atau perilaku tidak terduga.
* **CVSS v3.1**: 5.0 (Medium ;)) (medium njir cuman memory leak sama thread race condition)
* **Versi Terpengaruh**: WhatsApp Desktop for Windows hingga versi 2.2320.2
* **Referensi**: [NVD](https://nvd.nist.gov/vuln/detail/CVE-2023-38538)
* **Mitigasi dari saya**: (kalau perlu bisa check dulu kenapa kok ada kemungkinan futexnya nggak bisa handler si shared resources)

### 2.2 CVE-2023-38537

* **Deskripsi**: Kondisi balapan pada subsistem transport jaringan menyebabkan *heap use-after-free* dalam panggilan audio/video masuk yang sudah terhubung atau tidak dibisukan.
* **Dampak**: Potensi crash atau perilaku tidak terduga.
* **CVSS v3.1**: 5.6 (Medium)
* **Versi Terpengaruh**: WhatsApp Desktop for Mac OS X hingga versi 2.2338.12
* **Referensi**: [NVD](https://nvd.nist.gov/vuln/detail/CVE-2023-38537)
* **Mitigasi dari saya**: (Njir masih zaman ;) wtf use after free anjr masak pointer segede itu nggak kelihatan TwT)

### 2.3 CVE-2024-45607

* **Deskripsi**: Kesalahan kontrol akses pada metode `verifyRequestSignature` dalam *whatsapp-api-js* memungkinkan pemrosesan pesan tanpa validasi yang benar.
* **Dampak**: Potensi pemrosesan pesan tidak sah, berimplikasi pada integritas data.
* **CVSS v3.1**: 5.3 (Medium)
* **Versi Terpengaruh**: `whatsapp-api-js` versi 4.0.0 hingga 4.0.2
* **Referensi**: [NVD](https://nvd.nist.gov/vuln/detail/CVE-2024-45607)
* **Mitigasi dari saya**: (Uhmm.. kalau ini agak restrict attacknya ya.. aku nggak bisa handler kalau soal api leak)
