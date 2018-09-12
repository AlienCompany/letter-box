<?php
/**
 * Created by IntelliJ IDEA.
 * User: ferna
 * Date: 08/09/2018
 * Time: 10:37
 */
require "letterLog.php";

$ip = getClientIp();

letterLog('[INFO] clientIp: '.$ip." url: /testlog.php");


?>
