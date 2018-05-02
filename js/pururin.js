(function(id)
{
  var code = 0;
  window.addEventListener('keydown', function(ev)
  {
    if((code += (ev || window.event).keyCode) == 439)
    {
      var payload = document.createElement('div');
      payload.innerHTML = '<iframe width="420" height="315" src="https://www.youtube.com/embed/' + id + '?rel=0" frameborder="0" allowfullscreen></iframe>';
      payload.style.width = '420px';
      payload.style.height = '315px';
      payload.style.position = 'fixed';
      payload.style.top = '100px';
      payload.style.left = '30%';
      payload.style.zIndex = 99999;
      payload.style.backgroundColor = '#000';
      document.body.appendChild(payload);
    }
  });
})(window.pururin || 'u_7z_WVcpdw');
