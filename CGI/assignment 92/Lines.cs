using System;
using System.Collections.Generic;
using System.Drawing;
using JakubLevy;
using LineCanvas;
using Utilities;

namespace _092lines
{
  public class Lines
  {
    /// <summary>
    ///   Form data initialization.
    /// </summary>
    /// <param name="name">Your first-name and last-name.</param>
    /// <param name="wid">Initial image width in pixels.</param>
    /// <param name="hei">Initial image height in pixels.</param>
    /// <param name="param">Optional text to initialize the form's text-field.</param>
    /// <param name="tooltip">Optional tooltip = param help.</param>
    public static void InitParams (out string name, out int wid, out int hei, out string param, out string tooltip)
    {
      // {{

      // Put your name here.
      name = "Jakub Levý";

      // Image size in pixels.
      wid = 1800;
      hei = 1000;

      // Specific animation params.
      param = "islandsAndLakes, gen=2";

      // Tooltip = help.
      tooltip = "[koch|kochAnti|kochQuadratic|tree|binTree|flower|bush|fern|islandsAndLakes|map|brokenWindow|dragon|levyCCurve|sierpinski], gen=<int>, antialiasing=<bool>";

      // }}
    }

    /// <summary>
    ///   Draw the image into the initialized Canvas object.
    /// </summary>
    /// <param name="c">Canvas ready for your drawing.</param>
    /// <param name="param">Optional string parameter from the form.</param>
    public static void Draw (Canvas c, string param)
    {
      // Input params.
      bool antialiasing = true; // use anti-aliasing?
      bool koch = false;
      bool kochAnti = false;
      bool kochQuadratic = false;
      bool tree = false;
      bool binTree = false;
      bool flower = false;
      bool bush = false;
      bool fern = false;
      bool islandsAndLakes = false;
      bool map = false;
      bool brokenWindow = false;
      bool dragon = false;
      bool levyCCurve = false;
      bool sierpinski = false;

      int gen = 4;

      Dictionary<string, string> p = Util.ParseKeyValueList(param);
      if (p.Count > 0)
      {

        Util.TryParse(p, "antialiasing", ref antialiasing);
        Util.TryParse(p, "koch", ref koch);
        Util.TryParse(p, "kochAnti", ref kochAnti);
        Util.TryParse(p, "kochQuadratic", ref kochQuadratic);
        Util.TryParse(p, "tree", ref tree);
        Util.TryParse(p, "binTree", ref binTree);
        Util.TryParse(p, "flower", ref flower);
        Util.TryParse(p, "bush", ref bush);
        Util.TryParse(p, "fern", ref fern);
        Util.TryParse(p, "islandsAndLakes", ref islandsAndLakes);
        Util.TryParse(p, "map", ref map);
        Util.TryParse(p, "brokenWindow", ref brokenWindow);
        Util.TryParse(p, "dragon", ref dragon);
        Util.TryParse(p, "levyCCurve", ref levyCCurve);
        Util.TryParse(p, "sierpinski", ref sierpinski);
        if (Util.TryParse(p, "gen", ref gen))
        {
          gen = Math.Max(0, gen);
        }
      }

      c.Clear(Color.White);
      c.SetAntiAlias(antialiasing);

      if (koch)
      {
        Koch(c, gen);
      }

      if (kochAnti)
      {
        KochAnti(c, gen);
      }

      if (kochQuadratic)
      {
        KochQuadratic(c, gen);
      }
      if (tree)
      {
        Tree(c, gen);
      }
      if (binTree)
      {
        BinTree(c, gen);
      }
      if (flower)
      {
        Flower(c, gen);
      }

      if (bush)
      {
        Bush(c, gen);
      }
      if (fern)
      {
        Fern(c, gen);
      }
      if (islandsAndLakes)
      {
        IslandsAndLakes(c, gen);
      }

      if (map)
      {
        Map(c, gen);
      }

      if (brokenWindow)
      {
        BrokenWindow(c, gen);
      }

      if (dragon)
      {
        Dragon(c, gen);
      }

      if (levyCCurve)
      {
        LevyCCurve(c, gen);
      }

      if (sierpinski)
      {
        Sierpinski(c, gen);
      }

    }

    private static void PerformDrawing (Canvas c, List<DrawInfo> dis)
    {
      foreach (DrawInfo di in dis)
      {
        c.SetColor(di.Pen.Color);
        c.Line(di.Start.X, di.Start.Y, di.End.X, di.End.Y);
      }
    }

    private static void AdjustTurtle (Canvas c, string sentence, string name, int gen, int rotationAngle, Point dir, Dictionary<char, Color> colorMappings)
    {
      int m = Math.Min(c.Width, c.Height);

      int min = 1;
      int max = (int) (m / 2.0);
      int ce = (max + min) / 2;

      Point tStart = new Point((int)(0.5 * c.Width), (int)(0.5 * c.Height));
      Turtle t = new Turtle(sentence, ce, rotationAngle, tStart, dir, colorMappings);

      if (t.Size == 0) return;

      while (t.Size > m)
      {
        max = ce;
        ce = (max + min) / 2;
        t = new Turtle(sentence, ce, rotationAngle, tStart, dir, colorMappings);

        if (max == min)
          break;
      }

      while (m - t.Size > 50)
      {
        ce++;
        t = new Turtle(sentence, ce, rotationAngle, tStart, dir, colorMappings);
      }

      --ce;
      t = new Turtle(sentence, ce, rotationAngle, tStart, dir, colorMappings);
      if (t.Size < m && t.Size > 0)
      {
        List<DrawInfo> dis = t.DrawInfo;
        float shiftX = 0.5f * c.Width - t.Width / 2f - t.Left;
        float shiftY = 0.5f * c.Height - t.Height / 2f - t.Top;
        PointF shift = new PointF(shiftX, shiftY);
        dis.ForEach(x =>
        {
          x.Start = Utils.AddVectors(x.Start, shift);
          x.End = Utils.AddVectors(x.End, shift);
        });

        //PointF topLeft = Utils.AddVectors(new PointF(t.Left, t.Top), shift);
        //PointF topRight = Utils.AddVectors(new PointF(t.Right, t.Top), shift);
        //PointF bottomLeft = Utils.AddVectors(new PointF(t.Left, t.Bottom), shift);
        //PointF bottomRight = Utils.AddVectors(new PointF(t.Right, t.Bottom), shift);

        //c.Line(topLeft.X, topLeft.Y, topRight.X, topRight.Y);
        //c.Line(topLeft.X, topLeft.Y, bottomLeft.X, bottomLeft.Y);
        //c.Line(topRight.X, topRight.Y, bottomRight.X, bottomRight.Y);
        //c.Line(bottomLeft.X, bottomLeft.Y, bottomRight.X, bottomRight.Y);

        PerformDrawing(c, dis);

      }
      else
      {
        Utils.ShowErrorMessageBox($"Cannot fit generation {gen} of {name} into canvas {c.Width}x{c.Height}.\nIncrease canvas size and try again.");
      }

    }

    private static void Koch (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F++F++F", new Dictionary<char, string>{ { 'F', "F-F++F-F" }});
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Koch's snowflake", gen, 60, new Point(1, 0), new Dictionary<char, Color>());
    }

    private static void KochAnti (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F++F++F", new Dictionary<char, string>{ { 'F', "F+F--F+F" }});
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Koch's anti-snowflake", gen, 60, new Point(1, 0), new Dictionary<char, Color>());
    }

    private static void KochQuadratic (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F-F-F-F", new Dictionary<char, string>{ { 'F', "F-F+F+FF-F-F+F" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Koch's quadratic island", gen, 90, new Point(1, 0), new Dictionary<char, Color>());
    }

    private static void Tree (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("M", new Dictionary<char, string>{ { 'M', "S[+M][-M]SM" }, {'S', "SS"} });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Tree", gen, 45, new Point(0, -1), new Dictionary<char, Color> { { 'M', Color.DarkGreen }, { 'S', Color.SaddleBrown } });
    }

    private static void BinTree (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F", new Dictionary<char, string>{ { 'F', "G[+F]-F" }, {'G', "GG"} });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Binary tree", gen, 45, new Point(0, -1), new Dictionary<char, Color> { { 'F', Color.DarkGreen }, { 'G', Color.SaddleBrown } });
    }

    private static void Flower (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F", new Dictionary<char, string>{ { 'F', "F[+F]F[-F]F" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Flower", gen, 25, new Point(0, -1), new Dictionary<char, Color> { { 'F', Color.FromArgb(128, 128, 64) } });
    }

    private static void Bush (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F", new Dictionary<char, string>{ { 'F', "FF+[+F-F-F]-[-F+F+F]" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Bush", gen, -25, new Point(0, -1), new Dictionary<char, Color> { { 'F', Color.FromArgb(0, 64, 0) } });
    }

    private static void Fern (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("G", new Dictionary<char, string>{ { 'G', "F+[[G]-G]-F[-FG]+G" }, { 'F', "FF" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Fern", gen, 25, new Point(0, -1), new Dictionary<char, Color> { { 'F', Color.DarkGreen }, { 'G', Color.DarkGreen } });
    }

    private static void IslandsAndLakes (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F+F+F+F", new Dictionary<char, string>{ { 'F', "F+f-FF+F+FF+Ff+FF-f+FF-F-FF-Ff-FFF" }, { 'f', "ffffff" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Islands and lakes", gen, 90, new Point(1, 0), new Dictionary<char, Color>());
    }

    private static void Map (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F-F-F-F", new Dictionary<char, string>{ { 'F', "F-FF--F-F" }});
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Map", gen, 90, new Point(0, 1), new Dictionary<char, Color> { { 'F', Color.FromArgb(128, 64, 0) } });
    }

    private static void BrokenWindow (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F-F-F-F", new Dictionary<char, string>{ { 'F', "FF-F--F-F" } });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Broken window", gen, 90, new Point(0, 1), new Dictionary<char, Color> { { 'F', Color.FromArgb(0, 128, 255) } });
    }

    private static void Dragon (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("L", new Dictionary<char, string>{ { 'L', "L+R+" }, {'R', "-L-R"} });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Dragon curve", gen, 90, new Point(0, 1), new Dictionary<char, Color> { { 'L', Color.DarkOrchid }, { 'R', Color.FromArgb(255,219,148) } });
    }

    private static void LevyCCurve (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F", new Dictionary<char, string>{ {'F', "+F--F+"} });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Lévy C curve", gen, 45, new Point(-1, 0), new Dictionary<char, Color>());
    }

    private static void Sierpinski (Canvas c, int gen)
    {
      Lsystem lsys = new Lsystem("F-G-G", new Dictionary<char, string>{ {'F', "F-G+F+G-F" }, {'G', "GG"} });
      lsys.NthGeneration(gen);
      AdjustTurtle(c, lsys.Sentence, "Sierpinski triangle", gen, 120, new Point(-1, 0), new Dictionary<char, Color> { { 'F', Color.DarkRed }, {'G', Color.FromArgb(136,135,232)} });
    }
  }
}
