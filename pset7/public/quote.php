<?php
    // configuration
    require("../includes/config.php");

    if (empty($_SESSION["id"]))
        {
            redirect("login.php");
        } else if (empty($_POST["symbol"])) {
    
            //render form
            render("quote.php", ["title" => "Get Quote"]);
        } else {
        
        $stock = lookup($_POST["symbol"]);
        
        if(empty($stock)){
            apologize("invalid symbol");
        } else {
            $_SESSION['symbol'] = $stock["symbol"];
            $_SESSION['name'] = $stock["name"];
            $_SESSION['price'] = $stock["price"];
            render('quoted.php', ["title" => "Quoted"]);
            }
        }

?>