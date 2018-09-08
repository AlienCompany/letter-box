<?php
/**
 * Created by IntelliJ IDEA.
 * User: ferna
 * Date: 08/09/2018
 * Time: 10:37
 */

$today = date("d-m-Y");
//echo $today;
$fileName = 'log-'.$today.'.txt';

echo $fileName; // log-08-09-2018.txt

$monfichier = fopen('logs/'.$fileName ,'a+');

if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
    $ip = $_SERVER['HTTP_CLIENT_IP'];
} elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
    $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
} else {
    $ip = $_SERVER['REMOTE_ADDR'];
}

fputs($monfichier, '['.date("Y-m-d H:i:s").'] clientIp:'.$ip.' url: /testlog.php');

fclose($monfichier);

?>
