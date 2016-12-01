<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"]))
        {
            redirect("login.php");
        } else  if (isset($_POST["symbol"])) {
            
            $sharesPrice = CS50::query("SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            
            if (empty($sharesPrice) == true){
                apologize("can't get sharesprice");
            }
            
            $history = CS50::query("INSERT INTO history(user_id, transaction, symbol, datetime, shares, price) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], "SELL", $_POST["symbol"], date('l jS \of F Y h:i:s A'), $sharesPrice["shares"], $sharesPrice["price"]);
            
            if (empty($history) == true){
                apologize("can't update history");
            }
            
            $delete =  CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol =?", $_SESSION["id"],  $_POST["symbol"]);
            
           
            
            $updateCash = CS50::query("UPDATE users SET cash = cash - $cost WHERE id = ?", $_SESSION["id"]);
            
            if (empty($updateCash) == true){
                apologize("couldn't update cash with proceeds");
            }
            
            if ($delete == true){
                    redirect("portfolio.php");
                } else {
                
                //redirect to portfolio
                redirect("sell.php");
                }
        } else {
            
            $stocks = CS50::query("SELECT symbol FROM portfolio WHERE user_id = ?", $_SESSION["id"]);

            if(empty($stocks)){
                apologize("Can't retrieve portfolio stocks.");
            }  else {
              render('sell.php', ["title" => "Sold Stocks", "stocks" => $stocks]);
                
    
            }
        }

?>