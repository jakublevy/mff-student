<?php
require_once('db.php');

function delete_item_from_cart(int $item_id) : Bool {
    $stmt = $GLOBALS['_DBH']->prepare('delete from list where item_id = :itm;');
    $stmt->bindValue(':itm', $item_id, PDO::PARAM_INT);
    $stmt->execute();
    return $stmt->rowCount() === 1;
}
if(isset($_POST['del_item_id'])) {
    if(!delete_item_from_cart($_POST['del_item_id'])) {
        header("HTTP/1.1 500 Internal Server Error");
    }
}
?>