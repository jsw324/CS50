<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"]))
        {
            redirect("login.php");
        } else  if (isset($_POST["symbol"])) {
            
            $delete =  CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol =?", $_SESSION["id"],  $_POST["symbol"]);
            
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