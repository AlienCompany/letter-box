<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Letter-box logs</title>
</head>
<body>
    <h1>Letter-box logs</h1>
    <?php
    /**
     * Created by IntelliJ IDEA.
     * User: ferna
     * Date: 08/09/2018
     * Time: 12:09
     */
    error_reporting(E_ERROR | E_PARSE);


    if(isset($_GET["date"])){
        $date = $_GET["date"];
    }else{
        $date = date("d-m-Y");
    }

    $fileName = 'log-' . $date . '.txt';

    $monfichier = fopen('logs/' . $fileName, 'r');

    if ($monfichier) {

        for ($line = fgets($monfichier); $line !== false; $line = fgets($monfichier)) {
            // initialisation           conditions        itérations
            echo $line . "<br>";
        }
        fclose($monfichier);
    } else {
        // error opening the file.
        ?>
        <p>No logs found</p>
        <?php
    }


    ?>
</body>
</html>

