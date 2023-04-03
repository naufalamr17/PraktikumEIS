<?php
$hostname = "localhost";
$userDatabase = "root";
$passwordUser = "";
$databaseName = "esp";

$koneksi = mysqli_connect($hostname, $userDatabase, $passwordUser, $databaseName) or die (mysqli_error($koneksi));

$temperature = $_GET["temperature"];
$humidity = $_GET["humidity"];

$sql = mysqli_query($koneksi,"INSERT INTO sensor_data (temperature, humidity) VALUES ($temperature, $humidity)") or die (mysqli_error($koneksi));

if($sql) {
    echo "Data berhasil diinput";
} else {
    echo "Error";
}

$koneksi->close();
?>
