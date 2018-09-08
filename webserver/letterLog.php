<?php
/**
 * Created by IntelliJ IDEA.
 * User: ferna
 * Date: 08/09/2018
 * Time: 14:00
 */
function letterLog($logMessage)
{
    $today = date("d-m-Y");
//echo $today;
    $fileName = 'log-' . $today . '.txt';

    $monfichier = fopen('logs/' . $fileName, 'a+');

    fputs($monfichier, '[' . date("Y-m-d H:i:s") . '] ' . $logMessage . "\n");

    fclose($monfichier);
}

function getClientIp()
{
    if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
        $ip = $_SERVER['HTTP_CLIENT_IP'];
    } elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
        $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
    } else {
        $ip = $_SERVER['REMOTE_ADDR'];
    }
    return $ip;
}

?>