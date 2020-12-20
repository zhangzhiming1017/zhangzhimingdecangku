

String saveFilePaht="/storage/emulated/0/assets/labels/ppp.bmp";
File saveFile=new File(saveFilePaht);
if(!saveFile.exists()){
    try {
            saveFile.createNewFile();
            FileOutputStream fileOutputStream=new FileOutputStream(saveFile);
            if (fileOutputStream!=null) {
                //imageBitmap.compress(format, quality, stream);
                //把位图的压缩信息写入到一个指定的输出流中
                //第一个参数format为压缩的格式
                //第二个参数quality为图像压缩比的值,0-100.0 意味着小尺寸压缩,100意味着高质量压缩
                //第三个参数stream为输出流
                scaleImage.compress(Bitmap.CompressFormat.JPEG, 100, fileOutputStream);
                }
            fileOutputStream.flush();
            fileOutputStream.close();
            } catch (IOException e) {
            e.printStackTrace();
    }
}