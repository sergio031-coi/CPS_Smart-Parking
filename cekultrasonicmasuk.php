<?php 

	//membuat koneksi ke database

	$konek = mysqli_connect("localhost", "root", "", "dbparkiran" );

	//baca data dari tb_sensor
	$sql = mysqli_query($konek, "SELECT * FROM tb_sensor order by id desc");
	//data terakhir akan berada di atas


	//baca data paling atas
	$data = mysqli_fetch_array($sql);
	$UltrasonicMasuk = $data['UltrasonicMasuk'];

	//uji, apabila nilai ultrasonic masuk belum ada, maka anggap ultrasonic 0
	if( $UltrasonicMasuk == "") $UltrasonicMasuk = 0;

	//cetak nilai sensor
	echo $UltrasonicMasuk;
 ?>