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
    $subject = date('d/m/Y') . ': Boîte aux lettre, Le facteur est passé!';
    $message = 'Hello Coralie,' . "\r\n" . "\r\n";
    $headers = 'From: Ta boîte aux lettres <no-reply@letterbox.notraly.fr>' . "\r\n" .
               'X-Mailer: PHP/' . phpversion();

    $message .= "Voici le contenue de ta boîte aux lettres : " . "\r\n"; // a .= b   => a = a.b
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
        $message .= "Un ou plusieurs avis de passage." . "\r\n" . "\r\n";
    }else{
        $message .= "Aucun avis de passage." . "\r\n" . "\r\n";
    }

    $message .= "Bonne journée, Cordialement" . "\r\n";
    $message .= "Ta boite aux lettres" . "\r\n";

    mail($to, $subject, $message, $headers);
}

function sendCollectNotifMail(){
    $to = 'fernandez.coralie2001@gmail.com';
    $subject = date('d/m/Y') . ': Boîte aux lettre, Le facteur est passé!';
    $message = 'Hello Coralie,' . "\r\n" . "\r\n";
    $headers = 'From: Ta boîte aux lettres <no-reply@letterbox.notraly.fr>' . "\r\n" .
        'X-Mailer: PHP/' . phpversion();

    $message .= "Ta boîte aux lettres est vide." . "\r\n" . "\r\n";
    $message .= "Bonne journée, Cordialement" . "\r\n";
    $message .= "Ta boîte aux lettres" . "\r\n";

    mail($to, $subject, $message, $headers);
}
?>
