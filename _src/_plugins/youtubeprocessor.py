import os, doxter, re

class YouTubeProcessor(doxter.Processor):
    def __init__(self):
        self.regexp = re.compile(r'\[youtube=(.*?)\]', re.S)
        self.page = doxter.get_config('page')

    def priority(self):
        return -5

    def process(self, root, extension, content):
        if self.page.get('youtube') is True:
            return re.sub(self.regexp, lambda m: self.compose(m.group(1)), content)

        return content

    def compose(self, youtube_id):
        return '<iframe width="985" height="554" src="https://www.youtube.com/embed/%s" frameborder="0" allowfullscreen></iframe>' % (youtube_id)
