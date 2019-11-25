<?php
require_once('db.php');

function swap_order(int $prev_id, int $next_id) : Bool {
    $stmt = $GLOBALS['_DBH']->prepare('update list a inner join list b on a.item_id <> b.item_id set a.position = b.position where a.item_id in (:pa, :na) and b.item_id in (:pb, :nb);');
    $stmt->bindValue(':pa', $prev_id, PDO::PARAM_INT);
    $stmt->bindValue(':na', $next_id, PDO::PARAM_INT);
    $stmt->bindValue(':pb', $prev_id, PDO::PARAM_INT);
    $stmt->bindValue(':nb', $next_id, PDO::PARAM_INT);
    $stmt->execute();
    $v = $stmt->rowCount();
    return $stmt->rowCount() === 2;
}

if(isset($_POST['prev_id']) and isset($_POST['next_id'])) {
    if(!swap_order($_POST['prev_id'], $_POST['next_id'])) {
        header("HTTP/1.1 500 Internal Server Error");
    }
}
?>