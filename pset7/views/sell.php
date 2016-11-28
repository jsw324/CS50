<form action="sold.php" method="post">
    
    <select name="symbol" class="form-control center-block text-center" id="symbol">
        <?php foreach ($stocks as $symbol): ?>
            <option value="<?= $symbol["symbol"] ?>"name="symbol"><?= $symbol["symbol"] ?></option>
            <?php endforeach ?>
    </select>
  <br>
    <div class="form-group">
        <button class="btn btn-default" type="submit">
            <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
            Sell Stock
        </button>
    </div>
       

</form>
