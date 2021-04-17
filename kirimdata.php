<?php 
//koneksi ke database
$konek = mysqli_connect("localhost", "root", "", "dbparkiran" );


//baca data yang dirim data dari esp8266

$jarak1 = $_GET['jarak1'];
$kondisiPIR = $_GET['kondisiPIR'];
$jarak2 = $_GET['jarak2'];

//auto increment = 1 mengembalikan ID menjadi 1
mysqli_query($konek, "ALTER TABLE tb_sensor AUTO_INCREMENT = 1 ");

//simpan data sensor ke tabel tb_sensor

$simpan = mysqli_query($konek, "insert into tb_sensor( UltrasonicMasuk, SensorPIR, UltrasonicParkir)values('$jarak1', '$kondisiPIR', '$jarak2')");

//uji simpan untuk memberikan respon
if($simpan)
	echo "Berhasil dikrim";
else
	echo "Gagal Terkirim";

 ?>