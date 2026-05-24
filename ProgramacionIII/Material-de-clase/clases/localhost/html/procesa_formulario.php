<?php  //Llama al interprete

$nom = $_POST['nombre'];
$ape = $_POST['apellido'];
$mail = $_POST['email'];

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Procesa</title>
</head>
<body>
    <h1>Datos del formulario desde el servidor php</h1>
    <p>Nombre: <?php echo $nom; ?></p>
    <p>Apellido: <?php echo $ape; ?></p>
    <p>Email: <?php echo $mail; ?></p>
</body>
</html>

<?php



?>