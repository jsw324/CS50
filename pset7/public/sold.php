<?php

      // configuration
    require("../includes/config.php");
    
    // need to lookup current value of stock being sold and put proceeds from sale in bank account
    $currentPrice = lookup($_POST["symbol"]);
    
    if (empty($currentPrice)) {
        apologize("Can't find find current stock price");
    } else {
     //   $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $shares = CS50::query("SELECT * FROM portfolio WHERE symbol = ? AND user_id = ?", $_POST["symbol"], $_SESSION["id"]);
        
        if (empty($shares)) {
            apologize("can't retrieve shares");
        } else {
            echo intval($shares["shares"]);
            $sale =  ($currentPrice["price"] * $shares["shares"]);
            echo $sale;
            $newCash = CS50::query("UPDATE users SET cash = cash + $sale WHERE id = ?",  $_SESSION["id"]);
           }
        
    }
    
    $delete =  CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol =?", $_SESSION["id"],  $_POST["symbol"]);
                
    if (empty($delete)){
        apologize("sale failed");
    } else {
    
    //redirect to portfolio
    redirect("/");
    }
                
?>