import 'package:flutter/material.dart';

import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';

import 'main.dart';

class Webpage extends StatefulWidget {
  @override
  _WebpageState createState() => _WebpageState();
}

class _WebpageState extends State<Webpage> {
  @override
  Widget build(BuildContext context) {
    return WebviewScaffold(
      appBar: AppBar(
        title: Text(getlat +com+ getlon),
      ),


      url: "https://location10.herokuapp.com/formapp/"+arr[1]+"/"+arr[0],
      withJavascript: true,
      initialChild: Container(
        child: const Center(
          child: Text("Loading......"),

        ),
      ),
    );

  }
}
