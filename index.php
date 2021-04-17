<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Parkiran IOT</title>

    <script type="text/javascript" src="jquery/jquery.min.js"></script>

    <!-- load otomatis/realtime --->

    <script type="text/javascript">
      
      $(document).ready(function(){

        setInterval(function(){

          $("#cekultrasonicmasuk").load("cekultrasonicmasuk.php");
          $("#cekPIR").load("cekPIR.php");
          $("#cekultrasonicparkir").load("cekultrasonicparkir.php");
        }, 1000 );

      });
    </script>

  </head>
  <body>

    <div class="container" style="text-align: center; margin-top: 200px">

        <h2>Monitoring Sensor Parkiran <br> Telkom University</h2>

        <div style="display: flex;">

        <!-- menampilkan nilai sensor ultrasonic masuk -->
        <div class="card text-center" style="width: 33.33%">
          <div class="card-header " style  = " font-size : 30px; font-weight : bold; background-color: blue; color: white ">
            Ultrasonic Masuk
          </div>
          <div class="card-body">
            <h1> <span id="cekultrasonicmasuk"> 0 </span> </h1>
          </div>
        </div>
        <!--akhir menampilkan nilai sensor ultrasonic masuk -->


        <!-- menampilkan nilai sensor PIR masuk -->
        <div class="card text-center" style="width: 33.33%">
          <div class="card-header " style  = " font-size : 30px; font-weight : bold; background-color: red; color: white">
            PIR Masuk
          </div>
          <div class="card-body">
            <h1> <span id="cekPIR"> 0 </span> </h1>
          </div>
        </div>
        <!--akhir menampilkan nilai sensor PIR masuk -->


        <!-- menampilkan nilai sensor ultrasonic parkir -->
        <div class="card text-center" style="width: 33.33%">
          <div class="card-header " style  = " font-size : 30px; font-weight : bold; background-color: blue; color: white">
            Ultrasonic Parkir
          </div>
          <div class="card-body">
            <h1> <span id="cekultrasonicparkir"> 0 </span> </h1>
          </div>
        </div>
        <!--akhir menampilkan nilai sensor Parkir masuk -->


        <!--Menambahkan gambar -->
        

      </div>

    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
  </body>
</html>