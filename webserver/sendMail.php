<?php
/**
 * Created by IntelliJ IDEA.
 * User: ferna
 * Date: 15/09/2018
 * Time: 16:08
 */
function sendReceiveNotifMail()
{
    $to = 'fernandez.coralie2001@gmail.com';
    $subject = 'letter-box';
    $message = 'hello' . "\r\n";
    $headers = 'From: no-reply@letterbox.notraly.fr' . "\r\n" .
               'X-Mailer: PHP/' . phpversion();

    $message .= "Voici le contenue de votre boîte aux lettre : " . "\r\n"; // a .= b   => a = a.b
    if($_POST['letter'] == 1){
        $message .= "Une ou plusieurs lettres," . "\r\n";
    }else{
        $message .= "Aucune lettres," . "\r\n";
    }
    if($_POST['packet'] == 1){
        $message .= "Un ou plusieurs colis," . "\r\n";
    }else{
        $message .= "Aucun colis," . "\r\n";
    }
    if($_POST['callingCard'] == 1){
        $message .= "Un ou plusieurs avis de passage." . "\r\n";
    }else{
        $message .= "Aucun avis de passage." . "\r\n";
    }

    mail($to, $subject, $message, $headers);
}

function sendCollectNotifMail(){
    $to = 'fernandez.coralie2001@gmail.com';
    $subject = 'letter-box';
    $message = 'hello' . "\r\n";
    $headers = 'From: no-reply@letterbox.notraly.fr' . "\r\n" .
        'X-Mailer: PHP/' . phpversion();

    $message .= "Votre boîte aux lettres est vide" . "\r\n";

    mail($to, $subject, $message, $headers);
}
?>
