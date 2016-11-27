<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"]) || empty($_POST["password"]) || $_POST["password"] != $_POST["confirmation"]) {
            apologize("incorrect username or password");
        } else {
            //insert new user into databse 
             $rows = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        }
    }
    if (count($rows) == 1)
        {
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];

            // remember that user's now logged in by storing user's ID in session
            $_SESSION["id"] = $id;

            // redirect to portfolio
            redirect("/index.php");
        } else {
            apologize("unknown error");
        }

?>