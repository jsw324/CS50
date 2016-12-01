<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"])) {
        redirect("login.php");
    } else if (!isset($_POST["deposit"])){
        
        render("deposit.php");
    }else {
        
        $mon = $_POST["deposit"];
        
        $deposit = CS50::query("UPDATE users SET cash = cash + $mon WHERE id = ?", $_SESSION["id"]);
        
        $history = CS50::query("INSERT INTO history (user_id, transaction, symbol, datetime, shares, price) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], "DEPO", "", date('l jS \of F Y h:i:s A'), "", $mon);
     
        if(empty($deposit)){
            apologize("deposit didn't work");
        } else {
            redirect("/");
        }
     
     
    }
        ?>