<?php
/**
 * Created by IntelliJ IDEA.
 * User: ferna
 * Date: 08/09/2018
 * Time: 10:37
 */
require "letterLog.php";
require "sendMail.php";

$ip = getClientIp();

letterlog('[INFO] clientIp: ' . $ip . " url: /sendNotif.php");

if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    letterlog('[ERROR] NOT_POST_REQUEST: une requête POST est attendu');

} elseif (!isset($_POST['password'])) {
    letterlog('[ERROR] NOT_PASSWORD_IN_REQUEST: le paramètre "password" est manquant');

} elseif (!isset($_POST['notif'])) {
    letterlog('[ERROR] NOT_NOTIF_IN_REQUEST: le paramètre "notif" est manquant');

} elseif ($_POST['password'] !== 'iloveyouforever') {
    letterlog('[ERROR] WRONG_PASSWORD: le mot de passe est invalide');

} else {
    letterLog('[INFO] ' . 'notif: ' . $_POST['notif']);

    if($_POST['notif'] === 'receive'){
        if (!isset($_POST['letter'])) {
            letterlog('[ERROR] NOT_LETTER_IN_REQUEST: le paramètre "letter" est manquant');

        } elseif (!isset($_POST['packet'])) {
            letterlog('[ERROR] NOT_PACKET_IN_REQUEST: le paramètre "packet" est manquant');

        } elseif (!isset($_POST['callingCard'])) {
            letterlog('[ERROR] NOT_CALLINGCARD_IN_REQUEST: le paramètre "callingCard" est manquant');

        } else {
            letterlog('[INFO] ' . 'letter: ' . $_POST['letter'] . ' packet: ' . $_POST['packet'] . ' callingCard: ' . $_POST['callingCard']);
            sendReceiveNotifMail();
        }
    }elseif($_POST['notif'] === 'collect'){
        sendCollectNotifMail();

    }else{
        letterlog('[ERROR] WRONG_NOTIF_IN_REQUEST: le paramètre "notif" est invalide');
    }
}
?>