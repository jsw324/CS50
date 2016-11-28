<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"]))
        {
            redirect("login.php");
        } else if (!isset($_POST["symbol"])){
            render("buy.php", ["title" => "Buy Stock"]);
        } else if (preg_match("/^\d+$/", $_POST["shares"]) == true) {
            
            $stock = lookup($_POST["symbol"]);
            
            $cost = $stock["price"] * intval($_POST["shares"]);
            
            $cash = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
            
            foreach ($cash as $money){
                $dollar = $money["cash"];
            }
            
            if (empty($cash) || empty($cost)) {
                
                apologize("cash is empty");
               
               
               // NEED TO IMPLEMENT rejection when cost is greater than cash.  Variable $cost is not populating with correct value.
            } else if ($cost > $cash) {
                apologize("Sorry, you don't have enough cash");
            } else {
                $buy = CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], $_POST["shares"]);
                
                if ($buy == true){
                    redirect("/");
                } else {
                    apologize("something went wrong");
                }
                
            }
            
        } else {
            
            apologize("error");
        }

?>