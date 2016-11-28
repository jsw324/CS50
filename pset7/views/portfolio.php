<div class="container">
    <table class="table table-striped">
          <thead class="thead-inverse">
            <tr>
              <th>Symbol</th>
              <th>Name</th>
              <th>Shares</th>
              <th>Price</th>
              <th>TOTAL</th>
            </tr>
          </thead>
    
          <tbody>
            <?php foreach ($cash as $money): ?>
            <?php $dollars = $money["cash"] ?>
            <?php endforeach ?>
            <?php foreach ($positions as $position): ?>
            <?php $total = $position["price"] * $position["shares"] ?>
            <?php $dollars -= $total ?>
            <tr>
              <td><?= strtoupper($position["symbol"]) ?></td>
              <td><?= $position["name"] ?></td>
              <td><?= $position["shares"] ?></td>
              <td>$<?= money_format('%i', $position["price"]) ?></td>
              <td>$<?= money_format('%i', $total) ?></td>
            </tr>
            <?php endforeach ?>
           <tr>
               <td>CASH</td>
               <td></td>
               <td></td>
               <td></td>
               <td><strong>$<?= money_format('%i', $dollars) ?></strong></td>
           </tr>
         </tbody>
    </table>
</div>

 