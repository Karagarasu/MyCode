from yt_dlp import YoutubeDL

URLS = ['https://v.douyin.com/iDg5CWFk/']
with YoutubeDL() as ydl:
    ydl.download(URLS)