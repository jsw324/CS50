<div class="container">
    <table class="table table-striped">
          <thead class="thead-inverse">
            <tr>
              <th>Transaction</th>
              <th>Date/Time</th>
              <th>Symbol</th>
              <th>Shares</th>
              <th>Price</th>
            </tr>
          </thead>
    
          <tbody></tbody>
            
            <?php foreach ($history as $past): ?>
            
            <tr>
              <td><?= strtoupper($past["transaction"]) ?></td>
              <td><?= $past["datetime"]  ?></td>
              <td><?= $past["symbol"] ?></td>
              <td><?= $past["shares"] ?></td>
              <td>$<?= money_format('%i', $past["price"]) ?></td>
            </tr>
            <?php endforeach ?>
           
         </tbody>
    </table>
</div>

 