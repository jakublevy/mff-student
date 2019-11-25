<?php
require_once('db.php');

function update_amount(int $item_id, int $new_amount) : Bool {
    $stmt = $GLOBALS['_DBH']->prepare('update list set amount = :amnt where item_id = :itm;');
    $stmt->bindValue(':amnt', $new_amount, PDO::PARAM_INT);
    $stmt->bindValue(':itm', $item_id, PDO::PARAM_INT);
    $stmt->execute();
    return $stmt->rowCount() === 1;
}
if(isset($_POST['item_id']) and isset($_POST['new_amount'])) {
    if(!update_amount($_POST['item_id'], $_POST['new_amount'])) {
        header("HTTP/1.1 500 Internal Server Error");
    }
}
?>