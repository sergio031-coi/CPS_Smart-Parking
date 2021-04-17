<?php 

//membuat koneksi ke database

$konek = mysqli_connect("localhost", "root", "", "dbparkiran" );

//baca data dari tb_sensor
$sql = mysqli_query($konek, "SELECT * FROM tb_sensor order by id desc");
//data terakhir akan berada di atas


//baca data paling atas
$data = mysqli_fetch_array($sql);
$SensorPIR = $data['SensorPIR'];

//uji, apabila nilai PIR masuk belum ada, maka anggap PIR 0
if( $SensorPIR == "") $SensorPIR = 0;

//cetak nilai sensor
echo $SensorPIR;
 ?>