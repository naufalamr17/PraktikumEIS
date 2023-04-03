<?php
$hostname = "localhost";
$userDatabase = "root";
$passwordUser = "";
$databaseName = "esp";

$koneksi = mysqli_connect($hostname, $userDatabase, $passwordUser, $databaseName) or die(mysqli_error($koneksi));

$temperature = $_GET["temperature"];
$humidity = $_GET["humidity"];

$sql = "INSERT INTO sensor_data (temperature, humidity) VALUES ($temperature, $humidity)";

if ($koneksi->query($sql)===TRUE) {
    echo "Data berhasil diinput";
} else {
    echo "Error: " . $sql . "<br>" . $koneksi->error;
}

$koneksi->close();
?>