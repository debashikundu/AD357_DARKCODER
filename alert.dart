import 'package:flutter/material.dart';
import 'package:webview/main.dart';

var number =25;


class Alert extends StatefulWidget {
  @override
  _AlertState createState() => _AlertState();
}


class _AlertState extends State<Alert> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          title: Text("Alert !!!! "),
      ),

      body: Container(
         child: Center(
          child: Column(

              children: <Widget>[
                
                Text("Alert about flood will be shown up here"),

              ]


    )
      )
      )
    );
  }
}
