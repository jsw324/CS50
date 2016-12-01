<?php

      // configuration
    require("../includes/config.php");
    
    // need to lookup current value of stock being sold and put proceeds from sale in bank account
    $currentPrice = lookup($_POST["symbol"]);
   

    $shares = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
    //dump($shares[0]["shares"]);
    if (empty($shares)) {
        apologize("can't retrieve shares");
    } 

    $sh = $shares[0]["shares"];
    $pr = $currentPrice["price"];
    
    $sale =  $sh * $pr;
    
    $newCash = CS50::query("UPDATE users SET cash = cash + $sale WHERE id = ?",  $_SESSION["id"]);
    
    
    $history = CS50::query("INSERT INTO history (user_id, transaction, symbol, datetime, shares, price) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], "SELL", $_POST["symbol"], date('l jS \of F Y h:i:s A'), $shares[0]["shares"], $currentPrice["price"]);
        
    $delete =  CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol =?", $_SESSION["id"],  $_POST["symbol"]);
                
    if (empty($delete)){
        apologize("sale failed");
    } else {
    
    //redirect to portfolio
    redirect("/");
    }
                
?>