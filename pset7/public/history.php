<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"])) {
        redirect("login.php");
    } else {
        $history = CS50::query("SELECT * FROM history where user_id = ?", $_SESSION["id"]);
        
        if (empty($history) == true){
            apologize("empty history");
        } else {
            render('history.php', ["history" => $history]);
        }
    }
    
    
    ?>