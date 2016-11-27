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
            <?php foreach ($positions as $position): ?>
            <tr>
              <td><?= $position["symbol"] ?></td>
              <td><?= $position["name"] ?></td>
              <td><?= $position["shares"] ?></td>
              <td><?= $position["price"] ?></td>
              <td><?= $position["price"] * $position["shares"] ?></td>
            </tr>
            <?php endforeach ?>
           
         </tbody>
    </table>
</div>

 